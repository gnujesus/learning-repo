import { Injectable } from '@nestjs/common';
import res from './mock-data/res.json';

@Injectable()
export class AppService {
  getSchedule(): any {
    return res;
  }
}
