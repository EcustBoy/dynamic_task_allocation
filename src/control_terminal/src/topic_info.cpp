#include <topic_info.h>

Topic_Info::Topic_Info()
{
    ros::Time::init();
    nh_= boost::make_shared<ros::NodeHandle>();
    terminalinfo_publish_timer_ = nh_->createTimer(ros::Duration(0.03),&Topic_Info::publish,this);
    terminal2robot_pub_ = nh_->advertise<allocation_common::terminal2robot_info>("/control_terminal/terminal2robot_info",1);
    terminal2gazebo_pub_ = nh_->advertise<allocation_common::terminal2gazebo_info>("/control_terminal/terminal2gazebo_info",1);
    terminal2robot_pub_info_.all_allocation_robot_info.resize(MAXNUM_AGENT);
    terminal2robot_pub_info_.all_allocation_task_info.resize(MAXNUM_AGENT);
    terminal2gazebo_pub_info_.all_allocation_robot_info.resize(MAXNUM_AGENT);
    terminal2gazebo_pub_info_.all_allocation_task_info.resize(MAXNUM_AGENT);
    terminal2robots_info.allocation_mode=ALLOCATION_STOP;

    for(int i=0;i<MAXNUM_AGENT;i++)
        allocation2terminal_sub_[i]=nh_->subscribe <allocation_common::allocation2terminal_info>
                ("Robot"+std::to_string(i)+"/task_allocation/allocation2terminal_info",10,boost::bind(&Topic_Info::update_allocation_info,this,_1,i));
}

Topic_Info::~Topic_Info()
{

}

/// \brief publish the terminal info
void Topic_Info::publish(const ros::TimerEvent &)
{
    terminal2gazebo_pub_info_.isNew_allocation=terminal2gazebo_info.isNew_allocation;
    //pub the terminal2gazebo_info, the world will spawn the robots and tasks
    if(terminal2gazebo_info.isNew_allocation)
    {
        //only publish when initialize a new allocation
        for(int i=0;i<terminal2gazebo_info.task_pos_x.size();i++)
        {
            terminal2gazebo_pub_info_.task_pos_x.push_back(terminal2gazebo_info.task_pos_x[i]);
            terminal2gazebo_pub_info_.task_pos_y.push_back(terminal2gazebo_info.task_pos_y[i]);
        }
        for(int i=0;i<terminal2gazebo_info.robot_pos_x.size();i++)
        {
            terminal2gazebo_pub_info_.robot_pos_x.push_back(terminal2gazebo_info.robot_pos_x[i]);
            terminal2gazebo_pub_info_.robot_pos_y.push_back(terminal2gazebo_info.robot_pos_y[i]);
        }
        terminal2gazebo_info.isNew_allocation=false;
    }
    terminal2gazebo_pub_.publish(terminal2gazebo_pub_info_);

    //pub the terminal2robot_info, control the allocation mode
    terminal2robot_pub_info_.allocation_mode=terminal2robots_info.allocation_mode;
    terminal2robot_pub_info_.greedorprobability=terminal2robots_info.greedorprobability;
    terminal2robot_pub_info_.recordornot=terminal2robots_info.recordornot;
    terminal2robot_pub_info_.powerordistance=terminal2robots_info.powerordistance;

    terminal2robot_pub_.publish(terminal2robot_pub_info_);
}
void
Topic_Info::run()
{
    ros::spin();
}

/// \brief each robot publish its allocation_info to the terminal node, and the terminal node put them in one message, then publish to the robots
void Topic_Info::update_allocation_info(const allocation_common::allocation2terminal_info::ConstPtr & _msg, int topic_id)
{
    allocation_common::allocation_robot_info _tmp_robot_info;
    allocation_common::allocation_task_info  _tmp_task_info;

    _tmp_robot_info.isvalid=_msg->robot_info.isvalid;
    _tmp_robot_info.robot_ID=_msg->robot_info.robot_ID;
    _tmp_robot_info.robot_mode=_msg->robot_info.robot_mode;
    _tmp_robot_info.which_target=_msg->robot_info.which_target;
    _tmp_robot_info.which_task=_msg->robot_info.which_task;

    //the robot_power is certained by control_terminal, not task_allocation
    _tmp_robot_info.robot_power=terminal2robots_info.all_allocation_robot_info[_tmp_robot_info.robot_ID].robot_power;

    _tmp_task_info.current_distance=_msg->task_info.current_distance;
    _tmp_task_info.iscomplete=_msg->task_info.iscomplete;
    _tmp_task_info.isexplored=_msg->task_info.isexplored;
    _tmp_task_info.istarget=_msg->task_info.istarget;
    _tmp_task_info.known_power=_msg->task_info.known_power;
    _tmp_task_info.task_ID=_msg->task_info.task_ID;

    //the task_power is certained by control_terminal, not task_allocation
    _tmp_task_info.task_power=terminal2robots_info.all_allocation_task_info[_tmp_task_info.task_ID].task_power;

    terminal2robot_pub_info_.all_allocation_robot_info[topic_id]=_tmp_robot_info;
    terminal2robot_pub_info_.all_allocation_task_info[topic_id]=_tmp_task_info;
    terminal2gazebo_pub_info_.all_allocation_robot_info[topic_id]=_tmp_robot_info;
    terminal2gazebo_pub_info_.all_allocation_task_info[topic_id]=_tmp_task_info;
}