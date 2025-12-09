import { Module } from '@nestjs/common';
import { AppController } from './app.controller';
import { AppService } from './app.service';
import { ScreenModule } from './screen/screen.module';
import { ScheduleModule } from './schedule/schedule.module';

@Module({
  imports: [ScreenModule, ScheduleModule],
  controllers: [AppController],
  providers: [AppService],
})
export class AppModule {}
