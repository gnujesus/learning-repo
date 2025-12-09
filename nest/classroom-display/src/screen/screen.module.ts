import { Module } from '@nestjs/common';
import { ScreenGateway } from './screen/screen.gateway';
import { HelperService } from '@app/helper/helper.service';

@Module({
  providers: [ScreenGateway, HelperService],
})
export class ScreenModule { }
