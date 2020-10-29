void Move(void) //
{
    HalfSpeed = 0;//全速模式
    if(Halflag == 1)
        HalfSpeed = 1;//如果超声检测需要半速,改半速
    //按指令行车
    if(ctrl_comm_last != ctrl_comm)         //指令发生变化
    {
        ctrl_comm_last = ctrl_comm;
        switch(ctrl_comm)
        {
            case COMM_UP:  //小车前进  
            {   
                CarGo();
                break;
            }
            case COMM_DOWN:  //小车后退
            {
                CarBack();
                break;
            }
            case COMM_LEFT:  //小车左转
            {
                CarLeft();//motor.c里编程
                break;
            }
            case COMM_RIGHT: //小车右转
            {
                CarRight();//motor.c里编程
                break;
            }
            case COMM_STOP:  //小车停车
            {
                CarStop();
                break;
            }
            default : break;
        }
        Delayms(2);//防抖
    }
