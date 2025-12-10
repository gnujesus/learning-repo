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
import {
  WEBSOCKET_NAMESPACE,
} from '@app/constants/websocket.constants';

@WebSocketGateway({
  cors: { origin: '*' },
  namespace: WEBSOCKET_NAMESPACE, // main namespace: {url}/screens 
})
export class ScreenGateway implements OnGatewayConnection, OnGatewayDisconnect {
  @WebSocketServer()
  server: Server;

  private readonly logger = new Logger(ScreenGateway.name);

  constructor(private readonly helperService: HelperService) { }

  // Connection lifecycle

  handleConnection(client: Socket) {
    const code: string = client.handshake.query.classroom as string;
    console.log(code);

    if (!code) {
      client.disconnect();
      this.logger.fatal('[ERROR] Client tried to connect without classroom parameter. Disconected.');
      return;
    }

    const classroom: Classroom = this.helperService.parseClassroomCode(code);
    client.join(`building:${classroom.building}:room:${classroom.room}`)
    client.join(`room:${classroom.room}`)

    this.logger.log(
      `[CONNECTED] Screen connected to building:${classroom.building}:room:${classroom.room}.`,
    );
  }

  handleDisconnect(client: Socket) {
    const code: string = this.helperService.extractCodeFromNamespace(
      client.nsp.name,
    );
    const classroom: Classroom = this.helperService.parseClassroomCode(code);

    this.logger.warn(
      `[DISCONNECTED] Screen from classroom ${classroom.building}-${classroom.room} disconnected.`,
    );
  }

  sendToClassroom(code: string, event: string, data: any) {
    const classroom: Classroom = this.helperService.parseClassroomCode(code);
    this.logger.log(`[SEND] Event: ${event} to building:${classroom.building}:room:${classroom.room}`);

    this.server
      .of('/screens')
      .to(`building:${classroom.building}:room:${classroom.room}`)
      .emit(event, data);
    // namespace.emit(event, data);
  }

  broadcastToAll(event: string, data: any) {
    this.logger.warn(`[SEND] Event: ${event}; To all classrooms`); // a warning, since this could be a dangerous operation

    this.server.emit(event, data);
  }

  registerToRoom(room: string, asignee: string) {

  }
}

// ws://localhost:3000/screens/AH302
