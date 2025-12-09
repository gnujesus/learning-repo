import { Test, TestingModule } from '@nestjs/testing';
import { ScreenGateway } from './screen.gateway';

describe('ScreenGateway', () => {
  let gateway: ScreenGateway;

  beforeEach(async () => {
    const module: TestingModule = await Test.createTestingModule({
      providers: [ScreenGateway],
    }).compile();

    gateway = module.get<ScreenGateway>(ScreenGateway);
  });

  it('should be defined', () => {
    expect(gateway).toBeDefined();
  });
});
