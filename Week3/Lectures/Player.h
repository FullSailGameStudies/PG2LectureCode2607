#pragma once
#include <string>
class Player
{
	//access modifiers:
	//public: ALL code can see it
	//private: *ONLY this class can see it (default)
	//protected: (inheritance) this class and all classes that are
	//		descendents of this class can see it
public:

	//getters/setters - gatekeepers of the fields
	//   they are usually DEFINED in the header
	//	 reason: performance. the compiler can optimize their usage
	// 
	//getters (accessors) - provides access to the values
	//   usually const methods
	//	 return type matches the field type
	//   no parameters
	const std::string& GetGamerTag() const { return gamerTag_; }
	int Level() const { return level_; }

	//setters (mutators)
	//  cannot be const
	//  allow others to change the field
	//  return type is usually void
	//  parameter that matches the type of the field
	//  sometimes has validation logic inside
	void SetGamerTag(const std::string& newName)
	{
		//validation logic
		if (newName.size() > 0 && newName.size() <= 32)
		{
			gamerTag_ = newName;
		}
	}
	void Level(int level)
	{
		if (level > 0 && level == level_ + 1)
		{
			level_ = level;
		}
	}


private:
	//FIELDS (data members or member variable)
	//  data that describes the object
	//  naming convention:
	//		camelCasingNamingConvention
	//		add something extra to set it apart from other variables
	//		m_sGamerTag, m_gamerTag, mGamerTag, _gamerTag, gamerTag_
	std::string gamerTag_;
	int level_, health_;

	void DoIt(int& level)
	{
		int lvl;
		level_ = level;
	}
};

