import { Module } from '@nestjs/common';
import { ScreenGateway } from './screen/screen.gateway';

@Module({
  providers: [ScreenGateway]
})
export class ScreenModule {}
