import { Logger } from '@nestjs/common';
import { SubscribeMessage, WebSocketGateway, WebSocketServer, OnGatewayConnection, OnGatewayDisconnect } from '@nestjs/websockets';
import { Server, Socket } from 'socket.io';

@WebSocketGateway({
  cors: { origin: '*' },
  namespace: /^\/screens\/[A-Z0-9]+$/
})
export class ScreenGateway implements OnGatewayConnection, OnGatewayDisconnect {
  handleConnection(client: Socket) {
    throw new Error('Method not implemented.');
  }

  handleDisconnect(client: Socket) {
    throw new Error('Method not implemented.');
  }

  private readonly logger = new Logger(ScreenGateway.name);

  @WebSocketServer();
  private readonly server: Server;


}
