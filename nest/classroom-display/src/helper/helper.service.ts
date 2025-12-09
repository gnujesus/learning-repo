import { Injectable } from '@nestjs/common';
import { Classroom } from '@app/types/classroom.types';

@Injectable()
export class HelperService {
  parseClassroomCode(code: string): Classroom {
    const classroom: Classroom = {
      building: code.slice(0, 2),
      room: code.slice(2, code.length),
    };

    return classroom;
  }

  extractCodeFromNamespace(namespace: string): string {
    return namespace.split('/').pop() || '';
  }
}
