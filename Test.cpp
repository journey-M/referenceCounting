#include <iostream>
#include "./RefBase.h"
#include "./StrongPointer.h"

class MObject:public LightRefBase<MObject>
{
	public:
		MObject(){
				std::cout<<"MObject 构造函数"<<std::endl;
		}

		~MObject(){
				std::cout<<"MObject 析构～～～"<<std::endl;
		}

};
class NormalObject {
	public:
		NormalObject(){
			std::cout<<"NormalObject 构造函数"<<std::endl;
		}
		~NormalObject(){
			std::cout<<"NormalObject析构～～"<<std::endl;
		}

};

int main(int argc, char**argv){
		MObject* ligth = new MObject();
		std::cout<<"引用次数为:"<< ligth->getStrongCount()<<std::endl;
		sp<MObject> lp = ligth;
		std::cout<<"第一次引用-引用次数为:"<< ligth->getStrongCount()<<std::endl;

		{
			sp<MObject> lp2 = lp;
			std::cout<<"大括号中: 引用次数为:"<< ligth->getStrongCount()<<std::endl;

		}
		std::cout<<"引用次数为:"<< ligth->getStrongCount()<<std::endl;

		//std::cout<<"end"<<std::endl;
		
		//NormalObject* nObj = new NormalObject();

}
