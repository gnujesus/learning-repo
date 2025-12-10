import { Logger } from '@nestjs/common';
import {
  WebSocketGateway,
  WebSocketServer,
  OnGatewayConnection,
  OnGatewayDisconnect,
} from '@nestjs/websockets';
import { Socket, Server } from 'socket.io';
import { Classroom } from '@app/types/classroom.types';
import { HelperService } from '@app/helper/helper.service';
import { WEBSOCKET_NAMESPACE } from '@app/constants/websocket.constants';
import scheduleData from '../../mock-data/res.json';

@WebSocketGateway({
  cors: { origin: '*' },
  namespace: WEBSOCKET_NAMESPACE, // main namespace: {url}/screens
})
export class ScreenGateway implements OnGatewayConnection, OnGatewayDisconnect {
  @WebSocketServer()
  server: Server;

  private readonly logger = new Logger(ScreenGateway.name);

  constructor(private readonly helperService: HelperService) {}

  // Connection lifecycle

  handleConnection(client: Socket) {
    const code: string = client.handshake.query.classroom as string;

    if (!code) {
      client.disconnect();
      this.logger.fatal(
        '[ERROR] Client tried to connect without classroom parameter. Disconected.',
      );
      return;
    }

    const classroom: Classroom = this.helperService.parseClassroomCode(code);
    client.join(`building:${classroom.building}`);
    client.join(`building:${classroom.building}:room:${classroom.room}`);

    this.logger.log(
      `[CONNECTED] Screen connected to building:${classroom.building}:room:${classroom.room}.`,
    );

    const schedule = scheduleData.find((s) => s.classroom === code);

    if (schedule) {
      client.emit('updateSchedule', schedule);
      this.logger.log(`[INITIAL SCHEDULE] Sent to ${code}`);
      console.log(code);
    } else {
      this.logger.warn(`[WARNING] No schedule found for ${code}`);
    }
  }

  handleDisconnect(client: Socket) {
    const code: string = client.handshake.query.classroom as string;
    const classroom: Classroom = this.helperService.parseClassroomCode(code);

    this.logger.warn(
      `[DISCONNECTED] Screen from classroom building:${classroom.building}:room:${classroom.room} disconnected.`,
    );
  }

  sendToBuilding(building: string, event: string, data: any) {
    this.server.of('/screens').to(`building:${building}`).emit(event, data);
    this.logger.log(`[SEND] Event: ${event} to building:${building}`);
  }

  sendToClassroom(code: string, event: string, data: any) {
    const classroom: Classroom = this.helperService.parseClassroomCode(code);

    this.server
      .of('/screens')
      .to(`building:${classroom.building}:room:${classroom.room}`)
      .emit(event, data);

    this.logger.log(
      `[SEND] Event: ${event} to building:${classroom.building}:room:${classroom.room}`,
    );
    // namespace.emit(event, data);
  }

  broadcastToAll(event: string, data: any) {
    this.logger.warn(`[SEND] Event: ${event}; To all classrooms`); // a warning, since this could be a dangerous operation

    this.server.emit(event, data);
  }
}

// ws://localhost:3000/screens/AH302
