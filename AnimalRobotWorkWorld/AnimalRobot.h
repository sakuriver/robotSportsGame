#pragma once

#include <cereal/cereal.hpp>
#include <cereal/archives/json.hpp>

#include <list>
#include <string>


using namespace std;

/// <summary>
/// AnimalGoldPointで動物ロボット同士で利用される専用ポイント
/// </summary>
class AgpInfo {
public:
	AgpInfo()
	{
		this->nowAgp = 0;
	}
	AgpInfo(int agp)
	{
		this->nowAgp = agp;
	}
	int nowAgp;
};


class ExpInfo {
public: 
	ExpInfo()
	{
		this->nowExp = 0;
		this->nowLevel = 1;
	}
	ExpInfo(int exp, int level)
	{
		this->nowExp = exp;
		this->nowLevel = level;
	}
	int nowExp;
	int nowLevel;

};

class AnimalRobotLiveTicketInfo {
public:
	AnimalRobotLiveTicketInfo()
	{
		this->nowTicket = 0;
	}
	AnimalRobotLiveTicketInfo(int nowTicket)
	{
		this->nowTicket = nowTicket;
	}
	int nowTicket;
};

class AnimalRobot
{
private:
	int id = 1;
	int speed = 100;
	int power = 30;
	int stamina = 50;
	int leftArmPartsId = 0;
	int rightArmPartsId = 0;
	std::string name;
	int hp = 0;
public:
	void setId(int id)
	{
		this->id = id;
	}
	void setHp(int hp)
	{
		this->hp = hp;
	}
	void setPower(int power)
	{
		this->power = power;
	}
	void setSpeed(int speed)
	{
		this->speed = speed;
	}
	int getId() { return this->id; }
	int getHp() { return this->hp; }
	int getPower() { return this->power; }
	int getSpeed() { return this->speed; }
	int getStamina() { return this->stamina; }

	template<class Archive>
	void serialize(Archive& archive)
	{
		archive(CEREAL_NVP(id), CEREAL_NVP(speed), CEREAL_NVP(power), CEREAL_NVP(stamina), CEREAL_NVP(leftArmPartsId), CEREAL_NVP(rightArmPartsId), CEREAL_NVP(name), CEREAL_NVP(hp));
	}

};

 class PlayerInformation 
{
      public:
		 void SetProfile(ExpInfo expInfo,AgpInfo agpInfo, AnimalRobotLiveTicketInfo liveTicketInfo, std::vector<AnimalRobot> robotlist) {
			 this->expInfo = expInfo;
			 this->agpInfo = agpInfo;
			 this->liveTicketInfo = liveTicketInfo;
			 this->robotList = robotlist;
		 }
		 PlayerInformation() {}
		 ExpInfo expInfo;
		 AgpInfo agpInfo;
		 AnimalRobotLiveTicketInfo liveTicketInfo;
		 /// <summary>
		 /// 所持しているロボット君
		 /// </summary>
		 std::vector<AnimalRobot> robotList;
		 
      private:
		 template<class Archive>
		 void serialize(Archive& archive)
		 {
			 archive(CEREAL_NVP(expInfo), CEREAL_NVP(agpInfo), CEREAL_NVP(liveTicketInfo), CEREAL_NVP(robotList));
		 }
};

 