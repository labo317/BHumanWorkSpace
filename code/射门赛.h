/** A test striker option without common decision */
option(Striker)
{
     float SHE_X = -500.0f;
     float SHE_Y = 0.0f; 
     float distance;
 initial_state(start)
  {
    transition
    {
     if(state_time > 3000)
         goto turnToBall;
    }
    action
    {

     LookForward();
     WalkToTarget(Pose2f(30.f, 30.f, 30.f), Pose2f(0_deg,400.f, 0.f));


    }
  }


  state(turnToBall)
  {
    transition
    {
      if(libCodeRelease.timeSinceBallWasSeen() > theBehaviorParameters.ballNotSeenTimeOut)
        goto searchForBall;
      if(std::abs(theBallModel.estimate.position.angle()) < 5_deg)
        goto walkToBall;
    }
    action
    {
      WalkToTarget(Pose2f(50.f, 50.f, 50.f), Pose2f(theBallModel.estimate.position.angle(), 0.f, 0.f));      //为啥是两个动作？
    }
  }

  state(walkToBall)
  {
    transition
    {
      if(libCodeRelease.timeSinceBallWasSeen() > theBehaviorParameters.ballNotSeenTimeOut)
        goto searchForBall;
      if(theBallModel.estimate.position.norm() < 700.f)
        goto alignToGoal;
    }
    action
    {
      WalkToTarget(Pose2f(50.f, 50.f, 50.f), theBallModel.estimate.position);
    }
  }

  state(alignToGoal)
  {
    transition
    {
      if(libCodeRelease.timeSinceBallWasSeen() > theBehaviorParameters.ballNotSeenTimeOut)
        goto searchForBall;
      if(std::abs(libCodeRelease.angleToOwnGoal) < 10_deg && std::abs(theBallModel.estimate.position.y()) < 100.f)//原程序
     // if(std::abs(theBallModel.estimate.position.y()) < 100.f)
        goto alignBehindBall;
    }
    action
    {

      WalkToTarget(Pose2f(100.f, 100.f, 100.f), Pose2f(libCodeRelease.angleToOwnGoal, theBallModel.estimate.position.x() - 800.f, theBallModel.estimate.position.y()));
    }
  }

  state(alignBehindBall)
  {
    transition
    {
      if(libCodeRelease.timeSinceBallWasSeen() > theBehaviorParameters.ballNotSeenTimeOut)
        goto searchForBall;
      if(libCodeRelease.between(theBallModel.estimate.position.y(), 40.f, 70.f)
          && libCodeRelease.between(theBallModel.estimate.position.x(), 160.f, 180.f)
         && std::abs(libCodeRelease.angleToOwnGoal) < 2_deg)
        goto kick;
       //if(libCodeRelease.between(theBallModel.estimate.position.y(), 20.f, 50.f)
        //  && libCodeRelease.between(theBallModel.estimate.position.x(), 175.f, 205.f)
      //    )
       // goto kick;
    }
    action
    {
      LookForward();
      WalkToTarget(Pose2f(80.f, 80.f, 80.f), Pose2f(libCodeRelease.angleToOwnGoal, theBallModel.estimate.position.x() - 170.f, theBallModel.estimate.position.y() - 50.f));
    }
  }

  state(kick)
  {
    transition
    {
      if(state_time > 5000 )
        goto tui;
    }
    action
    {
      KickForWard(KickRequest::kickForward,false);
      
    }
  }
  state(tui)
  {
    transition
    {
      if( state_time > 4000 )
        goto searchForBall;
    }
    action
    {
      LookForward();
      WalkToTarget(Pose2f(30.f, 30.f, 30.f), Pose2f(0_deg,-550.f, 0.f));
    }
  }
  
  state(searchForBall)
  {
    transition
    {
      if(libCodeRelease.timeSinceBallWasSeen() < 300)
        goto turnToBall;
      if(state_time > 7000 )
        goto standMiddel;
    }
    action
    {
      theHeadControlMode = HeadControl::leftAndRight;
      WalkAtSpeedPercentage(Pose2f(1.f, 0.f, 0.f));
    }
  }
  state(standMiddel)
    {   
            transition 
        {
           Pose2f relatePoint = AbsolutePointToRobot(theRobotPose,SHE_X,SHE_Y);
           distance = relatePoint.translation.norm();
           if ( distance < 10.0 )
           goto searchForBall;
        if(libCodeRelease.timeSinceBallWasSeen() < 300)
        goto turnToBall;
        }    
        action
        {  

          LookForward();
          Pose2f relatePoint=AbsolutePointToRobot(theRobotPose,SHE_X,SHE_Y);
          WalkToTarget(Pose2f(pi/8,1.f,1.f),relatePoint);
         }
       }
}    
