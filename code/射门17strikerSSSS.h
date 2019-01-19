/** A test striker option without common decision */
option(Striker)
{
  float she_X = -500.0f;
  float she_Y = 0.0f;
  float distance;
    initial_state(start)
  {
    transition
    {
      if(state_time > 1000)
        goto turnToBall;
    }
    action
    {
      theHeadControlMode = HeadControl::lookForward;
      Stand();
    }
  }

  state(turnToBall)
  {
    transition
    {
      if(theLibCodeRelease.timeSinceBallWasSeen > theBehaviorParameters.ballNotSeenTimeOut)
        goto searchForBall;
      if(std::abs(theBallModel.estimate.position.angle()) < 5_deg)
        goto walkToBall;
       
    }
    action
    {
      theHeadControlMode = HeadControl::lookForward;
      WalkToTarget(Pose2f(50.f, 50.f, 50.f), Pose2f(theBallModel.estimate.position.angle(), 0.f, 0.f));
    }
  }

  state(walkToBall)
  {
    transition
    {
      if(theLibCodeRelease.timeSinceBallWasSeen > theBehaviorParameters.ballNotSeenTimeOut)
        goto searchForBall;
      if(theBallModel.estimate.position.norm() < 500.f)
        goto alignToGoal;
    }
    action
    {
      theHeadControlMode = HeadControl::lookForward;
      WalkToTarget(Pose2f(50.f, 50.f, 50.f), theBallModel.estimate.position);
    }
  }

  state(alignToGoal)
  {
    transition
    {
      if(theLibCodeRelease.timeSinceBallWasSeen > theBehaviorParameters.ballNotSeenTimeOut)
        goto searchForBall;
      if(std::abs(theLibCodeRelease.angleToGoal) < 10_deg && std::abs(theBallModel.estimate.position.y()) < 100.f)
        goto alignBehindBall;
    }
    action
    {
      theHeadControlMode = HeadControl::lookForward;
      WalkToTarget(Pose2f(100.f, 100.f, 100.f), Pose2f(theLibCodeRelease.angleToGoal, theBallModel.estimate.position.x() - 400.f, theBallModel.estimate.position.y()));
    }
  }

  state(alignBehindBall)
  {
    transition
    {
      if(theLibCodeRelease.timeSinceBallWasSeen > theBehaviorParameters.ballNotSeenTimeOut)
        goto searchForBall;
      if(theLibCodeRelease.between(theBallModel.estimate.position.y(), 25.f, 35.f)
      && theLibCodeRelease.between(theBallModel.estimate.position.x(), 145.f, 160.f)
      && std::abs(theLibCodeRelease.angleToGoal) < 2_deg)
        goto kick;
    }
    action
    {
      theHeadControlMode = HeadControl::lookForward;
      WalkToTarget(Pose2f(80.f, 80.f, 80.f), Pose2f(theLibCodeRelease.angleToGoal, theBallModel.estimate.position.x() - 150.f, theBallModel.estimate.position.y() - 30.f));
    }
  }

  state(kick)
  {
    transition
    {
      if(state_time > 3000 || (state_time > 10 && action_done))
        goto tui;
    }
    action
    {
      theHeadControlMode = HeadControl::lookForward;
      InWalkKick(WalkKickVariant(WalkKicks::forward, Legs::left), Pose2f(theLibCodeRelease.angleToGoal, theBallModel.estimate.position.x() - 150.f, theBallModel.estimate.position.y() - 50.f));
    }
  }
   state(tui)
{
    transition
    {
        if( state_time >4000)
            goto searchForBall;
            
    }
    action
    {
     theHeadControlMode = HeadControl::lookForward;
     WalkToTarget(Pose2f(30.f, 30.f, 30.f), Pose2f(0_deg,-550.f, 0.f));  
    }
}
  state(searchForBall)
  {
    transition
    {
      if(theLibCodeRelease.timeSinceBallWasSeen < 300)
        goto turnToBall;
        if(state_time >7000)
            goto standMiddel;
    }
    action
    {
      theHeadControlMode = HeadControl::lookForward;
      WalkAtRelativeSpeed(Pose2f(1.f, 0.f, 0.f));
    }
  }
   state(standMiddel)
{
    transition
    {
        Pose2f relatePoint = AbsolutePointToRobot(theRobotPose,she_X,she_Y);
           distance = relatePoint.translation.norm();
           if ( distance < 10.0 )
           goto searchForBall;
           if(theLibCodeRelease.timeSinceBallWasSeen < 300)
               goto turnToBall;
    }
    action
    {
        LookForward();
          Pose2f relatePoint=AbsolutePointToRobot(theRobotPose,she_X,she_Y);
          WalkToTarget(Pose2f(pi/8,50.f,50.f),relatePoint);
    }
}
}
