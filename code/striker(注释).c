/** A test striker option without common decision */
//pose2f是什么
//以下均为库函数，可查找到
//WalkToTarget，该函数有参数
//WalkAtSpeedPercentage
//Stand
//SpecialAction
//InWalkKick
//GetUpEngine
//以下均为状态state
//turnToBall转向球？
//walkToBall走向球
//alignToGoal对准球门，goal是球门的意思
//alignBehindBall？？只有在这个状态里，才有可能踢kick
//kick踢
//searchForBall寻找球
//
option(Striker)
{
  initial_state(start)//初始状态（开始）
  {
    Transition//什么意思？过渡？
    {
      if(state_time > 1000)//如果statetime大于1000
        goto turnToBall;//则进入turntoball（转向球）状态（后面有状态介绍）
    }
    Action//动作
    {
      LookForward();//lookforward（向前看？）函数，库函数
      Stand();//stand函数，库函数
    }
  }
/********************************************************************/

  state(turnToBall)// turntoball（转向球）状态
  {
    transition
{
//库代码发布，从看到球的时间>行为参数。球不见，超时
    
if(libCodeRelease.timeSinceBallWasSeen() > theBehaviorParameters.ballNotSeenTimeOut)
        goto searchForBall;//进入searchforball寻找球的状态（有介绍）
    //  //abs为求绝对值的函数，5_deg为角度应该是5度
  if(std::abs(theBallModel.estimate.position.angle()) < 5_deg)
        goto walkToBall;//进入walktoball走向球状态（有介绍）
    }
    action
    {
      LookForward();//进入lookforward函数
      WalkToTarget(Pose2f(50.f, 50.f, 50.f), Pose2f(theBallModel.estimate.position.angle(), 0.f, 0.f));
//走向目标
    }
  }
/********************************************************************/
  state(walkToBall)//walktoball（走向球）状态
  {
    transition
{

  //库代码发布，从看到球的时间>行为参数。球不见，超时
      if(libCodeRelease.timeSinceBallWasSeen() > theBehaviorParameters.ballNotSeenTimeOut)
        goto searchForBall;//searchforball状态
      if(theBallModel.estimate.position.norm() < 500.f)
        goto alignToGoal;//对准球门？
    }
    action
    {
      LookForward();//lookforward（向前看）函数
      WalkToTarget(Pose2f(50.f, 50.f, 50.f), theBallModel.estimate.position);//走向目标
    }
  }
/********************************************************************/

  state(alignToGoal)//对准球门？
  {
    transition
    {//库代码发布，行为参数
      if(libCodeRelease.timeSinceBallWasSeen() > theBehaviorParameters.ballNotSeenTimeOut)
//库代码发布，从看到球的时间>行为参数。球不见，超时
        goto searchForBall;//寻找球
      if(std::abs(libCodeRelease.angleToGoal)<10_deg&&std::abs(theBallModel.estimate.position.y())< 100.f)
        goto alignBehindBall;//？
    }
    action
    {
      LookForward();//寻找球
      WalkToTarget(Pose2f(100.f,100.f,100.f),Pose2f(libCodeRelease.angleToGoal,theBallModel.estimate.position.x() - 400.f, theBallModel.estimate.position.y()));//走到目标
    }
  }
/********************************************************************/

  state(alignBehindBall)
  {
    transition
    {
      if(libCodeRelease.timeSinceBallWasSeen() > theBehaviorParameters.ballNotSeenTimeOut)
        goto searchForBall;
      if(libCodeRelease.between(theBallModel.estimate.position.y(), 20.f, 50.f)
          && libCodeRelease.between(theBallModel.estimate.position.x(), 140.f, 170.f)
          && std::abs(libCodeRelease.angleToGoal) < 2_deg)
        goto kick;//踢
    }
    action
    {
      LookForward();//寻找球
      WalkToTarget(Pose2f(80.f,80.f,80.f),Pose2f(libCodeRelease.angleToGoal, theBallModel.estimate.position.x() - 150.f, theBallModel.estimate.position.y() - 30.f));
    }
  }
/********************************************************************/

  state(kick)//kick踢，状态
  {
    transition
    {
      if(state_time > 3000 || (state_time > 10 && action_done))
        goto start;//转到start开始状态
    }
    action
    {
      LookForward();
InWalkKick(WalkKickVariant(WalkKicks::forward,Legs::left),Pose2f(libCodeRelease.angleToGoal,theBallModel.estimate.position.x()-160.f, theBallModel.estimate.position.y() - 55.f));
    }
  }
 /********************************************************************/
 
  state(searchForBall)
  {
    transition
    {
      if(libCodeRelease.timeSinceBallWasSeen() < 300)
        goto turnToBall;
    }
    action
    {
      LookForward();
      WalkAtSpeedPercentage(Pose2f(1.f, 0.f, 0.f));//以百分比速度行走
    }
  }
}
