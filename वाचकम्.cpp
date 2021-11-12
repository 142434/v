#include<iostream>
#include<list>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<SDL2/SDL.h>

typedef double सङ्ख्या;

enum वर्णः {मौनम्,लघुमौनम्=-1,अत्=1,आत्,इत्,ईत्,उत्,ऊत्,ऋत्,ॠत्,ऌत्,ॡत्,एत्,ऐत्,ओत्,औत्,
					कः,खः,गः,घः,ङः,चः,छः,जः,झः,ञः,टः,ठः,डः,ढः,णः,तः,थः,दः,धः,नः,पः,फः,बः,भः,मः,यः,रः,लः,वः,शः,षः,सः,हः,
					विसर्गः,अनुस्वारः};

[[maybe_unused]] constexpr वर्णः
		स्वरः[]={अत्,आत्,इत्,ईत्,उत्,ऊत्,ऋत्,ॠत्,ऌत्,ॡत्,एत्,ऐत्,ओत्,औत्},
		ह्रस्वः[]={अत्,इत्,उत्,ऋत्,ऌत्},
		दीर्घः[]={आत्,ईत्,ऊत्,ॠत्,ॡत्,एत्,ऐत्,ओत्,औत्},
		उष्मा[]={शः,षः,सः,हः},
		अन्तःस्थः[]={यः,रः,लः,वः},
		नासिक्यः[]={अनुस्वारः,ङः,ञः,णः,नः,मः},
		वर्गीयः[]={कः,खः,गः,घः,ङः,चः,छः,जः,झः,ञः,टः,ठः,डः,ढः,णः,तः,थः,दः,धः,नः,पः,फः,बः,भः,मः},
		कवर्गीयः[]={कः,खः,गः,घः,ङः},
		चवर्गीयः[]={चः,छः,जः,झः,ञः},
		टवर्गीयः[]={टः,ठः,डः,ढः,णः},
		तवर्गीयः[]={तः,थः,दः,धः,नः},
		पवर्गीयः[]={पः,फः,बः,भः,मः},
		खरः[]={कः,चः,टः,तः,पः},
		अतिखरः[]={खः,छः,ठः,थः,फः},
		मृदुः[]={गः,जः,डः,दः,बः},
		घोषः[]={घः,झः,ढः,धः,भः};
		
		
	template <size_t गणना>
	bool अधिकारः(वर्णः द्रष्टव्यः,const वर्णः (&गणः)[गणना])
	{
		for(int क्रमः=0;क्रमः<गणना;क्रमः++)if(द्रष्टव्यः==गणः[क्रमः])return true;
		return false;
	}

struct वदनम्
	{
		int भागाः,नासिक्यभागाः,नासिकास्थानम्;
		सङ्ख्या शब्दवेगः=343.0,मुखदैर्घ्यम्,*मुखविस्तारः,*नासिकाविस्तारः,*बाह्यम्,*आन्तरिकम्,*नासिक्यबाह्यम्,*नासिक्यान्तरिकम्;
		वदनम्(int भागेभ्यः,int नासिकास्थानाय,सङ्ख्या मुखदैर्घ्याय)
		{
			भागाः=भागेभ्यः;
			नासिकास्थानम्=नासिकास्थानाय;
			नासिक्यभागाः=भागाः-नासिकास्थानम्;
			मुखदैर्घ्यम्=मुखदैर्घ्याय;
			मुखविस्तारः=new सङ्ख्या[भागाः];
			नासिकाविस्तारः=new सङ्ख्या[नासिक्यभागाः];
			बाह्यम्=new सङ्ख्या[भागाः]();
			आन्तरिकम्=new सङ्ख्या[भागाः]();
			नासिक्यबाह्यम्=new सङ्ख्या[नासिक्यभागाः]();
			नासिक्यान्तरिकम्=new सङ्ख्या[नासिक्यभागाः]();
		}
		
		~वदनम्()
		{
			delete[] मुखविस्तारः;delete[] नासिकाविस्तारः;delete[] बाह्यम्;delete[] आन्तरिकम्;delete[] नासिक्यबाह्यम्;delete[] नासिक्यान्तरिकम्;
		}
		सङ्ख्या निर्गतिः()
		{
			return (बाह्यम्[भागाः-1]+आन्तरिकम्[भागाः-1]+नासिक्यबाह्यम्[नासिक्यभागाः-1]+नासिक्यान्तरिकम्[नासिक्यभागाः-1]);
		}
		void योजनम्(int भागः,सङ्ख्या मात्रा)
		{
			बाह्यम्[भागः]+=मात्रा/2.0;
			आन्तरिकम्[भागः]+=मात्रा/2.0;
		}
		सङ्ख्या प्रवाहः(सङ्ख्या कण्ठ्यम्)
		{
			सङ्ख्या नवबाह्यम्[भागाः+1],नवान्तरिकम्[भागाः+1],नवनासिक्यबाह्यम्[नासिक्यभागाः+1],नवनासिक्यान्तरिकम्[नासिक्यभागाः+1];
			for(int भागः=1;भागः<भागाः;भागः++)
			{
				सङ्ख्या प्रत्यागतिः=(मुखविस्तारः[भागः-1]-मुखविस्तारः[भागः])/(मुखविस्तारः[भागः-1]+मुखविस्तारः[भागः])*(बाह्यम्[भागः-1]+आन्तरिकम्[भागः]);
				नवबाह्यम्[भागः]=बाह्यम्[भागः-1]-प्रत्यागतिः;
				नवान्तरिकम्[भागः]=आन्तरिकम्[भागः]+प्रत्यागतिः;
			}
			for(int भागः=1;भागः<नासिक्यभागाः;भागः++)
			{
				सङ्ख्या प्रत्यागतिः=(नासिकाविस्तारः[भागः-1]-नासिकाविस्तारः[भागः])/(नासिकाविस्तारः[भागः-1]+नासिकाविस्तारः[भागः])*(नासिक्यबाह्यम्[भागः-1]+नासिक्यान्तरिकम्[भागः]);
				नवनासिक्यबाह्यम्[भागः]=नासिक्यबाह्यम्[भागः-1]-प्रत्यागतिः;
				नवनासिक्यान्तरिकम्[भागः]=नासिक्यान्तरिकम्[भागः]+प्रत्यागतिः;
			}
			
			नवबाह्यम्[0]=आन्तरिकम्[0]*0.75+कण्ठ्यम्;
			नवान्तरिकम्[भागाः]=बाह्यम्[भागाः-1]*(-0.85);
			नवनासिक्यान्तरिकम्[नासिक्यभागाः]=नासिक्यबाह्यम्[नासिक्यभागाः-1]*(-0.85);
			
			{
				सङ्ख्या योगः=मुखविस्तारः[नासिकास्थानम्]+मुखविस्तारः[नासिकास्थानम्-1]+नासिकाविस्तारः[0];
				{
					सङ्ख्या प्रत्यागतिः=(2.0*मुखविस्तारः[नासिकास्थानम्-1]-योगः)/योगः;
					नवान्तरिकम्[नासिकास्थानम्]=प्रत्यागतिः*बाह्यम्[नासिकास्थानम्-1]+(1.0+प्रत्यागतिः)*(नासिक्यान्तरिकम्[0]+आन्तरिकम्[नासिकास्थानम्]);
				}
				{
					सङ्ख्या प्रत्यागतिः=(2.0*मुखविस्तारः[नासिकास्थानम्]-योगः)/योगः;
					नवबाह्यम्[नासिकास्थानम्]=प्रत्यागतिः*आन्तरिकम्[नासिकास्थानम्]+(1.0+प्रत्यागतिः)*(नासिक्यान्तरिकम्[0]+बाह्यम्[नासिकास्थानम्-1]);
				}
				{
					सङ्ख्या प्रत्यागतिः=(2.0*नासिकाविस्तारः[0]-योगः)/योगः;
					नवनासिक्यबाह्यम्[0]=प्रत्यागतिः*नासिक्यान्तरिकम्[0]+(1.0+प्रत्यागतिः)*(बाह्यम्[नासिकास्थानम्-1]+आन्तरिकम्[नासिकास्थानम्]);
				}
			}
			
			memcpy(बाह्यम्,नवबाह्यम्,भागाः*sizeof(सङ्ख्या));
			memcpy(आन्तरिकम्,नवान्तरिकम्+1,भागाः*sizeof(सङ्ख्या));
			memcpy(नासिक्यबाह्यम्,नवनासिक्यबाह्यम्,नासिक्यभागाः*sizeof(सङ्ख्या));
			memcpy(नासिक्यान्तरिकम्,नवनासिक्यान्तरिकम्+1,नासिक्यभागाः*sizeof(सङ्ख्या));
			
			return मुखदैर्घ्यम्/(सङ्ख्या)भागाः/शब्दवेगः;
		}
	};

class वाचकम्
{
public:
	वदनम् यन्त्रम्;
	सङ्ख्या कालः=0;
	int ग्रहणानि=0;
	int नैमिषिकानि=22050;
	class वर्णसङ्ग्रहः
	{
		static const int अवकाशः=20;
		std::pair<वर्णः,int> सङ्ग्रहः[अवकाशः];
		size_t स्थानम्=0,आदिः=0,अन्तः=0;
		bool लोपः=false;
	public:
		struct वर्णक्रमः
		{
			std::pair<वर्णः,int> (*क्रमणम्)(void*);
			void* अन्वयः;
		};
	private:
		 वर्णक्रमः वर्णाः;
	public:
		वर्णसङ्ग्रहः(वर्णक्रमः यद्वर्णाः)
		{
			वर्णाः=यद्वर्णाः;
			सङ्ग्रहः[0]=वर्णाः.क्रमणम्(वर्णाः.अन्वयः);
		}
		
		template <typename अङ्कनम्>
		void वृद्धिः(अङ्कनम् & अङ्कः){अङ्कः++;if(अङ्कः==अवकाशः)अङ्कः=0;}
		template <typename अङ्कनम्>
		अङ्कनम् अन्तरम्(const अङ्कनम् आदिः,const अङ्कनम् अन्तः)
		{
			if(अन्तः>=आदिः)return अन्तः-आदिः;
			else return अन्तः-आदिः+अवकाशः;
		}
		
		std::pair<वर्णः,int> पठनम्(int अतिक्रमः=0)
		{
			if(अतिक्रमः==0)return सङ्ग्रहः[स्थानम्];
			else if(अतिक्रमः<0)
			{
				if(-अतिक्रमः<=अन्तरम्(आदिः,स्थानम्))
				{
					int लक्ष्यः=स्थानम्+अतिक्रमः;
					if(लक्ष्यः<0)लक्ष्यः+=अवकाशः;
					return सङ्ग्रहः[लक्ष्यः];
				}
				else if(!लोपः)return std::make_pair(मौनम्,0);
				else throw(अतिक्रमः);
			}
			else
			{
				if(अतिक्रमः<=अन्तरम्(स्थानम्,अन्तः))
				{
					int लक्ष्यः=स्थानम्+अतिक्रमः;
					if(लक्ष्यः>अवकाशः)लक्ष्यः-=अवकाशः;
					return सङ्ग्रहः[लक्ष्यः];
				}
				else if(अतिक्रमः<अवकाशः)
				{
					int लक्ष्यः=स्थानम्+अतिक्रमः;
					if(लक्ष्यः>=अवकाशः)लक्ष्यः-=अवकाशः;
					while(अन्तः!=लक्ष्यः)
					{
						वृद्धिः(अन्तः);
						if(अन्तः==आदिः){वृद्धिः(आदिः);लोपः=true;}
						सङ्ग्रहः[अन्तः]=वर्णाः.क्रमणम्(वर्णाः.अन्वयः);
					}
					return सङ्ग्रहः[लक्ष्यः];
				}
				else throw(अतिक्रमः);
			}
		}
		void क्रमणम्()
		{
			if(स्थानम्!=अन्तः)वृद्धिः(स्थानम्);
			else
			{
				वृद्धिः(अन्तः);
				स्थानम्=अन्तः;
				if(अन्तः==आदिः){वृद्धिः(आदिः);लोपः=true;}
				सङ्ग्रहः[अन्तः]=वर्णाः.क्रमणम्(वर्णाः.अन्वयः);
			}
		}
	};
	वर्णसङ्ग्रहः पाठः;
	static const int भागसङ्ख्या=44,नासिकास्थानम्=16;
	वाचकम्(वर्णसङ्ग्रहः::वर्णक्रमः यद्वर्णाः):यन्त्रम्(भागसङ्ख्या,नासिकास्थानम्,0.17),पाठः(यद्वर्णाः)
	{
		std::fill_n(यन्त्रम्.मुखविस्तारः,यन्त्रम्.नासिकास्थानम्,0.5);
		std::fill_n(यन्त्रम्.मुखविस्तारः+यन्त्रम्.नासिकास्थानम्,यन्त्रम्.नासिक्यभागाः,1);
		std::fill_n(यन्त्रम्.नासिकाविस्तारः,यन्त्रम्.नासिक्यभागाः,1);
	}
	वाचकम्(const वाचकम् &)=delete;
	वाचकम्& operator=(const वाचकम् &)=delete;
	
	सङ्ख्या अनुदात्तस्य=100.0;
	सङ्ख्या उदात्तस्य=130.0;

	सङ्ख्या कण्ठ्यम्=0;
	सङ्ख्या कण्ठ्यान्तरम्=1/120.0,पूर्वकण्ठ्यान्तरम्=1/120.0,नवकण्ठ्यान्तरम्=पाठः.पठनम्().second==0?1/अनुदात्तस्य:1/उदात्तस्य;
	सङ्ख्या कण्ठ्यकालः=0.001;
	struct
	{
		सङ्ख्या आदिकालः=0,अन्तकालः=0.1;
		
		bool कण्ठ्यम्=false,कण्ठ्यभेदः=false;
		सङ्ख्या कण्ठ्यमात्राः[3],कण्ठ्यकालाः[4];
		
		bool विवारभेदः=false;
		सङ्ख्या विवारः[3][भागसङ्ख्या],विवारकालाः[4];
		bool विवृतम्=false;
		
		सङ्ख्या स्पर्शः=0,स्पर्शकालाः[4];
		int स्पर्शस्थानम्;
		
		सङ्ख्या श्वसनम्=0,श्वसनकालाः[4];
		
		सङ्ख्या नासिक्याः[3]={0.1,0.1,0.1},नासिक्यकालौ[2];
		
		सङ्ख्या आन्तरिकम्=0;
				
	}प्रयत्नः;
	सङ्ख्या योगः=0;
	void प्रभावः()
	{
		if(कालः>प्रयत्नः.अन्तकालः)पठनम्();
		कण्ठ्यान्तरम्=पूर्वकण्ठ्यान्तरम्+(नवकण्ठ्यान्तरम्-पूर्वकण्ठ्यान्तरम्)*(कालः-प्रयत्नः.आदिकालः)/(प्रयत्नः.अन्तकालः-प्रयत्नः.आदिकालः);
		if(प्रयत्नः.अन्तकालः==प्रयत्नः.आदिकालः)कण्ठ्यान्तरम्=पूर्वकण्ठ्यान्तरम्;
		if(प्रयत्नः.कण्ठ्यम्)
		{
			सङ्ख्या कण्ठ्यमात्रा;
			if(प्रयत्नः.कण्ठ्यभेदः)कण्ठ्यमात्रा=
				कालः<प्रयत्नः.कण्ठ्यकालाः[0]?प्रयत्नः.कण्ठ्यमात्राः[0]
				:कालः>प्रयत्नः.कण्ठ्यकालाः[3]?प्रयत्नः.कण्ठ्यमात्राः[2]
				:कालः<प्रयत्नः.कण्ठ्यकालाः[1]?
				(कालः-प्रयत्नः.कण्ठ्यकालाः[0])*(प्रयत्नः.कण्ठ्यमात्राः[1]-प्रयत्नः.कण्ठ्यमात्राः[0])/(प्रयत्नः.कण्ठ्यकालाः[1]-प्रयत्नः.कण्ठ्यकालाः[0])+प्रयत्नः.कण्ठ्यमात्राः[0]
				:कालः>प्रयत्नः.कण्ठ्यकालाः[2]?
				(कालः-प्रयत्नः.कण्ठ्यकालाः[2])*(प्रयत्नः.कण्ठ्यमात्राः[2]-प्रयत्नः.कण्ठ्यमात्राः[1])/(प्रयत्नः.कण्ठ्यकालाः[3]-प्रयत्नः.कण्ठ्यकालाः[2])+प्रयत्नः.कण्ठ्यमात्राः[1]
				:प्रयत्नः.कण्ठ्यमात्राः[1];
			else कण्ठ्यमात्रा=प्रयत्नः.कण्ठ्यमात्राः[1];
			सङ्ख्या कण्ठ्यावधिः=1/1750.0;
			if(कालः-कण्ठ्यकालः<कण्ठ्यावधिः&&कालः>=कण्ठ्यकालः)
			{
				कण्ठ्यम्=-कण्ठ्यमात्रा*4.0*(कालः-कण्ठ्यकालः)*(कण्ठ्यकालः+कण्ठ्यावधिः-कालः)/कण्ठ्यावधिः/कण्ठ्यावधिः;
			}
			else if(कालः-कण्ठ्यकालः>कण्ठ्यान्तरम्)
			{
				if(कालः-कण्ठ्यकालः<कण्ठ्यान्तरम्+कण्ठ्यान्तरम्)कण्ठ्यकालः+=कण्ठ्यान्तरम्*(1.0+0.0*(double)rand()/(double)RAND_MAX);
				else कण्ठ्यकालः=कालः;
			}
		}
		वर्णः उपस्थितः=पाठः.पठनम्(-1).first;
		if(अधिकारः(उपस्थितः,वर्गीयः)&&!अधिकारः(उपस्थितः,नासिक्यः))योगः+=अधिकारः(उपस्थितः,कवर्गीयः)?0.0002:0;
		else योगः=0;
		//कण्ठ्यम्+=योगः;
		if(प्रयत्नः.विवारभेदः)
		{
			auto विवरणम्=[this](सङ्ख्या *आद्यविवारः,सङ्ख्या *अन्त्यविवारः,सङ्ख्या स्थानम्)
			{
				for(int भागः=0;भागः<भागसङ्ख्या;भागः++)
					यन्त्रम्.मुखविस्तारः[भागः]=आद्यविवारः[भागः]*(1-स्थानम्)+स्थानम्*अन्त्यविवारः[भागः];
			};
			if(कालः<प्रयत्नः.विवारकालाः[0]&&!प्रयत्नः.विवृतम्){प्रयत्नः.विवृतम्=true;memcpy(यन्त्रम्.मुखविस्तारः+0,प्रयत्नः.विवारः[0]+0,sizeof(सङ्ख्या)*(भागसङ्ख्या-0));}
			else if(कालः>प्रयत्नः.विवारकालाः[0]&&कालः<प्रयत्नः.विवारकालाः[1])विवरणम्(प्रयत्नः.विवारः[0],प्रयत्नः.विवारः[1],(कालः-प्रयत्नः.विवारकालाः[0])/(प्रयत्नः.विवारकालाः[1]-प्रयत्नः.विवारकालाः[0]));
			else if(कालः>प्रयत्नः.विवारकालाः[2]&&कालः<प्रयत्नः.विवारकालाः[3])विवरणम्(प्रयत्नः.विवारः[1],प्रयत्नः.विवारः[2],(कालः-प्रयत्नः.विवारकालाः[2])/(प्रयत्नः.विवारकालाः[3]-प्रयत्नः.विवारकालाः[2]));
			if(उपस्थितः==रः)यन्त्रम्.मुखविस्तारः[(int)(0.6*(भागसङ्ख्या-1-नासिकास्थानम्)+नासिकास्थानम्)]+=0.00001*sin(कालः*100.0);
		}
		यन्त्रम्.नासिकाविस्तारः[0]=
			कालः<प्रयत्नः.नासिक्यकालौ[0]?प्रयत्नः.नासिक्याः[0]+(प्रयत्नः.नासिक्याः[1]-प्रयत्नः.नासिक्याः[0])*(कालः-प्रयत्नः.आदिकालः)/(प्रयत्नः.नासिक्यकालौ[0]-प्रयत्नः.आदिकालः)
			:कालः<प्रयत्नः.नासिक्यकालौ[1]?प्रयत्नः.नासिक्याः[1]
			:प्रयत्नः.नासिक्याः[1]+(प्रयत्नः.नासिक्याः[2]-प्रयत्नः.नासिक्याः[1])*(कालः-प्रयत्नः.नासिक्यकालौ[1])/(प्रयत्नः.अन्तकालः-प्रयत्नः.नासिक्यकालौ[1]);
		
		if(प्रयत्नः.स्पर्शः&&कालः>प्रयत्नः.स्पर्शकालाः[0]&&कालः<प्रयत्नः.स्पर्शकालाः[3])
		{
			सङ्ख्या मात्रा=प्रयत्नः.स्पर्शः*(
				कालः<प्रयत्नः.स्पर्शकालाः[1]?
				(कालः-प्रयत्नः.स्पर्शकालाः[0])/(प्रयत्नः.स्पर्शकालाः[1]-प्रयत्नः.स्पर्शकालाः[0])
				:कालः<प्रयत्नः.स्पर्शकालाः[2]?
				1.0
				:(प्रयत्नः.स्पर्शकालाः[3]-कालः)/(प्रयत्नः.स्पर्शकालाः[3]-प्रयत्नः.स्पर्शकालाः[2]));
			यन्त्रम्.योजनम्(प्रयत्नः.स्पर्शस्थानम्,मात्रा*((float)rand()/(float)RAND_MAX));
		}
		if(प्रयत्नः.श्वसनम्&&कालः>प्रयत्नः.श्वसनकालाः[0]&&कालः<प्रयत्नः.श्वसनकालाः[3])
		{
			सङ्ख्या मात्रा=प्रयत्नः.श्वसनम्*(
				कालः<प्रयत्नः.श्वसनकालाः[1]?
				(कालः-प्रयत्नः.श्वसनकालाः[0])/(प्रयत्नः.श्वसनकालाः[1]-प्रयत्नः.श्वसनकालाः[0])
				:कालः<प्रयत्नः.श्वसनकालाः[2]?
				1.0
				:(प्रयत्नः.श्वसनकालाः[3]-कालः)/(प्रयत्नः.श्वसनकालाः[3]-प्रयत्नः.श्वसनकालाः[2]));
			कण्ठ्यम्+=मात्रा*((float)rand()/(float)RAND_MAX);
		}
	}

	void पठनम्()
	{
		पूर्वकण्ठ्यान्तरम्=नवकण्ठ्यान्तरम्;
		//नवकण्ठ्यान्तरम्=(1.0/130.0)*(1.0+0.05*(सङ्ख्या)rand()/(सङ्ख्या)RAND_MAX);
		वर्णः पूर्वः=पाठः.पठनम्(-1).first,पश्चिमः=पाठः.पठनम्(1).first,उपस्थितः=पाठः.पठनम्().first;
		int स्वरभेदः=पाठः.पठनम्().second;
		if(स्वरभेदः<=1)नवकण्ठ्यान्तरम्=1/अनुदात्तस्य;
		else नवकण्ठ्यान्तरम्=1/उदात्तस्य;
		
		कालः-=प्रयत्नः.अन्तकालः;
		कण्ठ्यकालः-=प्रयत्नः.अन्तकालः;
		प्रयत्नः.आदिकालः=0;
		सङ्ख्या ह्रस्वावधिः=0.15;
		सङ्ख्या अवधिः=
			उपस्थितः==मौनम्?0.3
			:उपस्थितः==लघुमौनम्?0.1
			:अधिकारः(उपस्थितः,ह्रस्वः)?ह्रस्वावधिः
			:अधिकारः(उपस्थितः,दीर्घः)?ह्रस्वावधिः*2.0
			:उपस्थितः==रः&&!अधिकारः(पूर्वः,स्वरः)?0.1
			:उपस्थितः==रः&&अधिकारः(पूर्वः,स्वरः)&&अधिकारः(पश्चिमः,स्वरः)?0.06
			:अधिकारः(उपस्थितः,नासिक्यः)&&अधिकारः(पश्चिमः,स्वरः)?0.06
			:0.1;
		if(उपस्थितः==लघुमौनम्)उपस्थितः=मौनम्;
		if(पूर्वः==लघुमौनम्)पूर्वः=मौनम्;
		if(पश्चिमः==लघुमौनम्)पश्चिमः=मौनम्;
		
		प्रयत्नः.अन्तकालः=प्रयत्नः.आदिकालः+अवधिः;
		सङ्ख्या गतिः=0.002;
		प्रयत्नः.कण्ठ्यम्=अधिकारः(उपस्थितः,स्वरः)||अधिकारः(उपस्थितः,अन्तःस्थः)||अधिकारः(उपस्थितः,नासिक्यः)||अधिकारः(उपस्थितः,मृदुः)||अधिकारः(उपस्थितः,घोषः);
		if(प्रयत्नः.कण्ठ्यम्)
		{
			प्रयत्नः.कण्ठ्यभेदः=!((अधिकारः(पूर्वः,स्वरः)||अधिकारः(पूर्वः,अन्तःस्थः)||अधिकारः(पूर्वः,नासिक्यः))
				&&(अधिकारः(उपस्थितः,स्वरः)||अधिकारः(उपस्थितः,अन्तःस्थः)||अधिकारः(उपस्थितः,नासिक्यः))
				&&(अधिकारः(पश्चिमः,स्वरः)||अधिकारः(पश्चिमः,अन्तःस्थः)||अधिकारः(पश्चिमः,नासिक्यः)))||true;
			सङ्ख्या कण्ठ्यमात्रा=
				अधिकारः(उपस्थितः,मृदुः)||अधिकारः(उपस्थितः,घोषः)?1.2
				:1.0;
			प्रयत्नः.कण्ठ्यमात्राः[1]=
				उपस्थितः==ओत्?कण्ठ्यमात्रा*1
				:कण्ठ्यमात्रा/(अधिकारः(उपस्थितः,स्वरः)||अधिकारः(उपस्थितः,नासिक्यः)||अधिकारः(उपस्थितः,अन्तःस्थः)?1.5:1.0);
			प्रयत्नः.कण्ठ्यमात्राः[0]=
				अधिकारः(पूर्वः,घोषः)||अधिकारः(पूर्वः,अतिखरः)?0
				:कण्ठ्यमात्रा;//*(सङ्ख्या)((अधिकारः(पूर्वः,स्वरः)||अधिकारः(पूर्वः,अन्तःस्थः)||अधिकारः(पूर्वः,नासिक्यः))&&(अधिकारः(उपस्थितः,स्वरः)||अधिकारः(उपस्थितः,अन्तःस्थः)||अधिकारः(उपस्थितः,नासिक्यः)));
			प्रयत्नः.कण्ठ्यमात्राः[2]=कण्ठ्यमात्रा;//*(सङ्ख्या)((अधिकारः(पश्चिमः,स्वरः)||अधिकारः(पश्चिमः,अन्तःस्थः)||अधिकारः(पश्चिमः,नासिक्यः))&&(अधिकारः(उपस्थितः,स्वरः)||अधिकारः(उपस्थितः,अन्तःस्थः)||अधिकारः(उपस्थितः,नासिक्यः)));
			प्रयत्नः.कण्ठ्यकालाः[0]=प्रयत्नः.आदिकालः;
			प्रयत्नः.कण्ठ्यकालाः[1]=प्रयत्नः.कण्ठ्यकालाः[0]+
				अधिकारः(पूर्वः,घोषः)||अधिकारः(पूर्वः,अतिखरः)?0.03
				:गतिः;
			प्रयत्नः.कण्ठ्यकालाः[3]=प्रयत्नः.अन्तकालः;
			प्रयत्नः.कण्ठ्यकालाः[2]=प्रयत्नः.कण्ठ्यकालाः[3]-गतिः;
		}
		प्रयत्नः.विवारभेदः=true;
		प्रयत्नः.विवृतम्=false;
		प्रयत्नः.विवारकालाः[0]=
			(!अधिकारः(उपस्थितः,स्वरः))&&(!अधिकारः(पूर्वः,स्वरः))&&पूर्वः!=मौनम्?प्रयत्नः.आदिकालः+0.05
			:प्रयत्नः.आदिकालः;
		प्रयत्नः.विवारकालाः[1]=
			प्रयत्नः.विवारकालाः[0]+fminf(
			अधिकारः(पूर्वः,टवर्गीयः)||अधिकारः(पूर्वः,पवर्गीयः)?0.02
			:0.1
			,(प्रयत्नः.अन्तकालः-प्रयत्नः.विवारकालाः[0])/2.0);
		प्रयत्नः.विवारकालाः[3]=प्रयत्नः.अन्तकालः;
		प्रयत्नः.विवारकालाः[2]=
			प्रयत्नः.अन्तकालः-fminf(0.02,(प्रयत्नः.अन्तकालः-प्रयत्नः.विवारकालाः[0])/2.0);
			
		static constexpr वर्णः कण्ठावरोधः[]={अत्,आत्,कः,खः,गः,घः,ङः},
				ताल्ववरोधः[]={एत्,ऐत्,इत्,ईत्,चः,छः,जः,झः,ञः,यः,शः},
				मूर्धावरोधः[]={ऋत्,ॠत्,टः,ठः,डः,ढः,णः,रः,षः},
				दन्तावरोधः[]={ऌत्,ॡत्,तः,थः,दः,धः,नः,लः,सः},
				ओष्ठावरोधः[]={ओत्,औत्,उत्,ऊत्,पः,फः,बः,भः,मः,वः};
				
		auto स्थानम्=[](वर्णः उपस्थितः)->int
		{
			
			return (
				अधिकारः(उपस्थितः,कवर्गीयः)?0.
				:अधिकारः(उपस्थितः,कण्ठावरोधः)?0.
				:अधिकारः(उपस्थितः,ताल्ववरोधः)?0.4
				:उपस्थितः==रः?0.6
				:अधिकारः(उपस्थितः,मूर्धावरोधः)?0.6
				:अधिकारः(उपस्थितः,दन्तावरोधः)?0.85
				:उपस्थितः==वः?0.99
				:अधिकारः(उपस्थितः,ओष्ठावरोधः)?0.99
				:उपस्थितः==अनुस्वारः?नासिकास्थानम्
				:throw(उपस्थितः)
				)*(भागसङ्ख्या-1-नासिकास्थानम्)+नासिकास्थानम्;
		};
		auto विवारः=[स्थानम्](वर्णः उपस्थितः,int भागः)->सङ्ख्या
		{
			if(उपस्थितः==मौनम्||उपस्थितः==हः||उपस्थितः==विसर्गः)return 10.0;

			सङ्ख्या अवकाशः=
				उपस्थितः==अत्||उपस्थितः==आत्?0.05
				:उपस्थितः==रः?0.05
				:उपस्थितः==उत्||उपस्थितः==ऊत्||उपस्थितः==ओत्||उपस्थितः==औत्?0.05
				:अधिकारः(उपस्थितः,स्वरः)?0.1
				:अधिकारः(उपस्थितः,उष्मा)?0.0001
				:अधिकारः(उपस्थितः,नासिक्यः)||अधिकारः(उपस्थितः,वर्गीयः)?0.0001
				:अधिकारः(उपस्थितः,अन्तःस्थः)?0.05:10;
			
			int अवरोधः=स्थानम्(उपस्थितः);
			
			सङ्ख्या पूर्वविवारः=
				अधिकारः(उपस्थितः,कवर्गीयः)?0.5
				:अधिकारः(उपस्थितः,टवर्गीयः)?0.1
				:अधिकारः(उपस्थितः,पवर्गीयः)?0.5:0.1;
			
			सङ्ख्या  विवारः=
			(भागः<नासिकास्थानम्?0.5
			:उपस्थितः==अनुस्वारः?0.01
			:fminf(((अधिकारः(उपस्थितः,ताल्ववरोधः)||अधिकारः(उपस्थितः,ओष्ठावरोधः))&&(!अधिकारः(उपस्थितः,पवर्गीयः))?0.5:भागः<अवरोधः?1.0:1.5)
				,अवकाशः+(उपस्थितः==रः||उपस्थितः==ऋत्||उपस्थितः==ॠत्?0.1:अधिकारः(उपस्थितः,ताल्ववरोधः)?1.0:(अधिकारः(उपस्थितः,कवर्गीयः)||अधिकारः(उपस्थितः,टवर्गीयः)||अधिकारः(उपस्थितः,पवर्गीयः))&&!अधिकारः(उपस्थितः,नासिक्यः)?1.0:अधिकारः(उपस्थितः,नासिक्यः)?5.0:उपस्थितः==लः?20.0:भागः<अवरोधः?2.0:10.0)*abs(भागः-अवरोधः)/(सङ्ख्या)भागसङ्ख्या))
				+((अधिकारः(उपस्थितः,कवर्गीयः)||अधिकारः(उपस्थितः,टवर्गीयः)||अधिकारः(उपस्थितः,पवर्गीयः))&&(!अधिकारः(उपस्थितः,नासिक्यः)||true)&&उपस्थितः!=रः&&भागः<अवरोधः&&(सङ्ख्या)(अवरोधः-भागः)/(सङ्ख्या)नासिकास्थानम्<पूर्वविवारः?
				(अधिकारः(उपस्थितः,कवर्गीयः)||अधिकारः(उपस्थितः,पवर्गीयः)||अधिकारः(उपस्थितः,टवर्गीयः)?5.0:1.0)
				*(पूर्वविवारः-(सङ्ख्या)(अवरोधः-भागः)/(सङ्ख्या)नासिकास्थानम्)/पूर्वविवारः:0)
				+((अधिकारः(उपस्थितः,कवर्गीयः)||उपस्थितः==एत्||उपस्थितः==ओत्||उपस्थितः==ऐत्||उपस्थितः==औत्||उपस्थितः==आत्)&&भागः<नासिकास्थानम्&&भागः>नासिकास्थानम्*0.5?1.0*((भागः)/(सङ्ख्या)नासिकास्थानम्-0.5):0)
				;
			
			if(भागः<नासिकास्थानम्)return विवारः;
			
			if(उपस्थितः==एत्||उपस्थितः==ओत्||उपस्थितः==आत्)
				विवारः*=1.0+2.0*(भागः-नासिकास्थानम्)/(सङ्ख्या)(भागसङ्ख्या-1-नासिकास्थानम्);
			else if(उपस्थितः==ऐत्||उपस्थितः==औत्)
				विवारः*=1.0+5.0*(भागः-नासिकास्थानम्)/(सङ्ख्या)(भागसङ्ख्या-1-नासिकास्थानम्);
			return विवारः;
		};
	
		for(int भागः=0;भागः<भागसङ्ख्या;भागः++)
		{
			प्रयत्नः.विवारः[0][भागः]=
				(अधिकारः(उपस्थितः,वर्गीयः)||अधिकारः(उपस्थितः,अन्तःस्थः))&&(अधिकारः(पूर्वः,वर्गीयः)||पूर्वः==अनुस्वारः)&&पूर्वः!=मौनम्?विवारः(पूर्वः,भागः)
				:fminf(विवारः(पूर्वः,भागः),विवारः(उपस्थितः,भागः));
			प्रयत्नः.विवारः[1][भागः]=
				(अधिकारः(पूर्वः,वर्गीयः))&&(अधिकारः(उपस्थितः,वर्गीयः)||अधिकारः(उपस्थितः,अन्तःस्थः))&&(उपस्थितः==रः)&&अधिकारः(पश्चिमः,स्वरः)?0.1
				:विवारः(उपस्थितः,भागः);
			प्रयत्नः.विवारः[2][भागः]=
				(अधिकारः(पश्चिमः,वर्गीयः)||अधिकारः(पश्चिमः,अन्तःस्थः))&&(अधिकारः(उपस्थितः,वर्गीयः)||उपस्थितः==अनुस्वारः)&&उपस्थितः!=मौनम्?विवारः(उपस्थितः,भागः)
				:fminf(विवारः(पश्चिमः,भागः),विवारः(उपस्थितः,भागः));
		}
		
		bool दीर्घावरोधः=(अधिकारः(उपस्थितः,कवर्गीयः)&&अधिकारः(पश्चिमः,कवर्गीयः)&&पश्चिमः!=ङः)
			||(अधिकारः(उपस्थितः,चवर्गीयः)&&अधिकारः(पश्चिमः,चवर्गीयः)&&पश्चिमः!=ञः)
			||(अधिकारः(उपस्थितः,टवर्गीयः)&&अधिकारः(पश्चिमः,टवर्गीयः)&&पश्चिमः!=णः)
			||(अधिकारः(उपस्थितः,तवर्गीयः)&&अधिकारः(पश्चिमः,तवर्गीयः)&&पश्चिमः!=नः)
			||(अधिकारः(उपस्थितः,पवर्गीयः)&&अधिकारः(पश्चिमः,पवर्गीयः)&&पश्चिमः!=मः);
		
		प्रयत्नः.स्पर्शः=
			अधिकारः(उपस्थितः,उष्मा)&&उपस्थितः!=हः?0.004
			:उपस्थितः==वः||उपस्थितः==यः?0.002
			:उपस्थितः==रः||उपस्थितः==ऋत्||उपस्थितः==ॠत्?0.002
			:दीर्घावरोधः?0
			:अधिकारः(उपस्थितः,चवर्गीयः)&&उपस्थितः!=ञः?0.002
			:अधिकारः(उपस्थितः,वर्गीयः)&&!अधिकारः(उपस्थितः,नासिक्यः)?(अधिकारः(उपस्थितः,कवर्गीयः)?0.000:0.000)
			:0;
		if(प्रयत्नः.स्पर्शः)
		{
			प्रयत्नः.स्पर्शस्थानम्=स्थानम्(उपस्थितः);
			
			प्रयत्नः.स्पर्शकालाः[0]=
				अधिकारः(उपस्थितः,उष्मा)||उपस्थितः==वः||उपस्थितः==यः||उपस्थितः==रः||उपस्थितः==ऋत्||उपस्थितः==ॠत्?प्रयत्नः.आदिकालः+गतिः
				:अधिकारः(उपस्थितः,चवर्गीयः)?प्रयत्नः.आदिकालः+0.05
				:प्रयत्नः.अन्तकालः-
					(अधिकारः(उपस्थितः,कवर्गीयः)?0.001+0.04
					:0.001);
			प्रयत्नः.स्पर्शकालाः[1]=	
				अधिकारः(उपस्थितः,उष्मा)||उपस्थितः==वः||उपस्थितः==यः||उपस्थितः==रः||उपस्थितः==ऋत्||उपस्थितः==ॠत्?प्रयत्नः.स्पर्शकालाः[0]+गतिः
				:प्रयत्नः.स्पर्शकालाः[0];
			प्रयत्नः.स्पर्शकालाः[3]=
				अधिकारः(उपस्थितः,उष्मा)||उपस्थितः==वः||उपस्थितः==यः||उपस्थितः==रः||उपस्थितः==ऋत्||उपस्थितः==ॠत्?प्रयत्नः.अन्तकालः-गतिः
				:अधिकारः(उपस्थितः,कवर्गीयः)?प्रयत्नः.अन्तकालः-0.04
				:प्रयत्नः.अन्तकालः;
			प्रयत्नः.स्पर्शकालाः[2]=
				अधिकारः(उपस्थितः,उष्मा)||उपस्थितः==वः||उपस्थितः==यः||उपस्थितः==रः||उपस्थितः==ऋत्||उपस्थितः==ॠत्?प्रयत्नः.स्पर्शकालाः[3]-गतिः
				:प्रयत्नः.स्पर्शकालाः[3];
		}
		
		प्रयत्नः.श्वसनम्=
			उपस्थितः==हः||उपस्थितः==विसर्गः?0.005
			:उपस्थितः==रः?0.0
			:अधिकारः(पूर्वः,अतिखरः)||अधिकारः(पूर्वः,घोषः)?0.02
			:0;
		if(प्रयत्नः.श्वसनम्)
		{
			प्रयत्नः.श्वसनकालाः[0]=
				उपस्थितः==रः?प्रयत्नः.अन्तकालः-0.03
				:अधिकारः(पूर्वः,अतिखरः)||अधिकारः(पूर्वः,घोषः)?प्रयत्नः.आदिकालः
				:प्रयत्नः.आदिकालः;
			प्रयत्नः.श्वसनकालाः[1]=
				अधिकारः(पूर्वः,अतिखरः)||अधिकारः(पूर्वः,घोषः)?प्रयत्नः.श्वसनकालाः[0]
				:प्रयत्नः.श्वसनकालाः[0]+गतिः;
			प्रयत्नः.श्वसनकालाः[3]=
				अधिकारः(पूर्वः,अतिखरः)||अधिकारः(पूर्वः,घोषः)?प्रयत्नः.श्वसनकालाः[1]+0.03
				:प्रयत्नः.अन्तकालः-गतिः;
			प्रयत्नः.श्वसनकालाः[2]=
				अधिकारः(पूर्वः,अतिखरः)||अधिकारः(पूर्वः,घोषः)?प्रयत्नः.श्वसनकालाः[3]-0.00
				:प्रयत्नः.श्वसनकालाः[3]-गतिः;
		}
		
		प्रयत्नः.नासिक्याः[0]=
			अधिकारः(उपस्थितः,नासिक्यः)||अधिकारः(पूर्वः,नासिक्यः)?0.1
			:0.00001;
		प्रयत्नः.नासिक्याः[1]=अधिकारः(उपस्थितः,नासिक्यः)?0.1:अधिकारः(उपस्थितः,घोषः)||अधिकारः(उपस्थितः,मृदुः)?0.01:0.00001;
		प्रयत्नः.नासिक्याः[2]=
			अधिकारः(उपस्थितः,नासिक्यः)||अधिकारः(पश्चिमः,नासिक्यः)?0.1
			:0.00001;
		प्रयत्नः.नासिक्यकालौ[0]=
			अधिकारः(पूर्वः,नासिक्यः)&&!अधिकारः(पश्चिमः,नासिक्यः)?प्रयत्नः.आदिकालः+fminf(0.1,अवधिः*0.9)
			:अधिकारः(पश्चिमः,नासिक्यः)&&!अधिकारः(पूर्वः,नासिक्यः)?प्रयत्नः.आदिकालः+अवधिः*0.05
			:प्रयत्नः.आदिकालः+fminf(0.05,अवधिः/2.0);
		प्रयत्नः.नासिक्यकालौ[1]=
			अधिकारः(पश्चिमः,नासिक्यः)&&!अधिकारः(पूर्वः,नासिक्यः)?प्रयत्नः.अन्तकालः-fminf(0.1,अवधिः*0.9)
			:अधिकारः(पूर्वः,नासिक्यः)&&!अधिकारः(पश्चिमः,नासिक्यः)?प्रयत्नः.अन्तकालः-अवधिः*0.05
			:प्रयत्नः.अन्तकालः-fminf(0.05,अवधिः/2.0);
		
			
			
		प्रयत्नः.आन्तरिकम्=
			अधिकारः(उपस्थितः,घोषः)||अधिकारः(उपस्थितः,मृदुः)?0.0
			:0;
		
		पाठः.क्रमणम्();
	}
	
	सङ्ख्या ग्रहणम्()
	{
		while(true)
		{
			{
				कण्ठ्यम्=0;
				प्रभावः();
				कालः+=यन्त्रम्.प्रवाहः(कण्ठ्यम्);
			}
			{
				int कतिग्रहणानि=कालः*(सङ्ख्या)नैमिषिकानि;
				if(कतिग्रहणानि!=ग्रहणानि)
				{
					ग्रहणानि=कतिग्रहणानि;
					return (यन्त्रम्.निर्गतिः()+(यन्त्रम्.आन्तरिकम्[नासिकास्थानम्]+यन्त्रम्.आन्तरिकम्[नासिकास्थानम्+1])*प्रयत्नः.आन्तरिकम्*0)*3.0;
				}
			}
		}
	}
};

auto वर्णनिर्णयः(const char* पाठः)
{
	std::list<वर्णः> वर्णाः;
	std::list<int> स्वराः;
	std::list<int> स्वरक्रमः;
	auto समत्वम्=[](const char* प्रथमः,const char* द्वितीयः)
	{
		for(int क्रमः=0;क्रमः<3;क्रमः++)
			if(प्रथमः[क्रमः]!=द्वितीयः[क्रमः])return false;
		return true;
	};
	auto लक्ष्यः=[समत्वम्](const char* अङ्कः,वर्णः &उपस्थितः)
	{
		उपस्थितः=
			समत्वम्(अङ्कः,"क")?कः:समत्वम्(अङ्कः,"ख")?खः:समत्वम्(अङ्कः,"ग")?गः:समत्वम्(अङ्कः,"घ")?घः:समत्वम्(अङ्कः,"ङ")?ङः:
			समत्वम्(अङ्कः,"च")?चः:समत्वम्(अङ्कः,"छ")?छः:समत्वम्(अङ्कः,"ज")?जः:समत्वम्(अङ्कः,"झ")?झः:समत्वम्(अङ्कः,"ञ")?ञः:
			समत्वम्(अङ्कः,"ट")?टः:समत्वम्(अङ्कः,"ठ")?ठः:समत्वम्(अङ्कः,"ड")?डः:समत्वम्(अङ्कः,"ढ")?ढः:समत्वम्(अङ्कः,"ण")?णः:
			समत्वम्(अङ्कः,"त")?तः:समत्वम्(अङ्कः,"थ")?थः:समत्वम्(अङ्कः,"द")?दः:समत्वम्(अङ्कः,"ध")?धः:समत्वम्(अङ्कः,"न")?नः:
			समत्वम्(अङ्कः,"प")?पः:समत्वम्(अङ्कः,"फ")?फः:समत्वम्(अङ्कः,"ब")?बः:समत्वम्(अङ्कः,"भ")?भः:समत्वम्(अङ्कः,"म")?मः:
			समत्वम्(अङ्कः,"य")?यः:समत्वम्(अङ्कः,"र")?रः:समत्वम्(अङ्कः,"ल")?लः:समत्वम्(अङ्कः,"व")?वः:
			समत्वम्(अङ्कः,"श")?शः:समत्वम्(अङ्कः,"ष")?षः:समत्वम्(अङ्कः,"स")?सः:समत्वम्(अङ्कः,"ह")?हः:
			समत्वम्(अङ्कः,"ः")?विसर्गः:समत्वम्(अङ्कः,"ं")?अनुस्वारः:
			समत्वम्(अङ्कः,"अ")?अत्:समत्वम्(अङ्कः,"आ")||समत्वम्(अङ्कः,"ा")?आत्:समत्वम्(अङ्कः,"इ")||समत्वम्(अङ्कः,"ि")?इत्:समत्वम्(अङ्कः,"ई")||समत्वम्(अङ्कः,"ी")?ईत्:
			समत्वम्(अङ्कः,"उ")||समत्वम्(अङ्कः,"ु")?उत्:समत्वम्(अङ्कः,"ऊ")||समत्वम्(अङ्कः,"ू")?ऊत्:समत्वम्(अङ्कः,"ऋ")||समत्वम्(अङ्कः,"ृ")?ऋत्:समत्वम्(अङ्कः,"ॠ")||समत्वम्(अङ्कः,"ॄ")?ॠत्:
			समत्वम्(अङ्कः,"ऌ")||समत्वम्(अङ्कः,"ॢ")?ऌत्:समत्वम्(अङ्कः,"ॡ")||समत्वम्(अङ्कः,"ॣ")?ॡत्:समत्वम्(अङ्कः,"ए")||समत्वम्(अङ्कः,"े")?एत्:समत्वम्(अङ्कः,"ऐ")||समत्वम्(अङ्कः,"ै")?ऐत्:
			समत्वम्(अङ्कः,"ओ")||समत्वम्(अङ्कः,"ो")?ओत्:समत्वम्(अङ्कः,"औ")||समत्वम्(अङ्कः,"ौ")?औत्:समत्वम्(अङ्कः,"।")||समत्वम्(अङ्कः,"॥")?मौनम्:मौनम्;
			if(!(समत्वम्(अङ्कः,"।")||समत्वम्(अङ्कः,"॥"))&&उपस्थितः==मौनम्)return false;
			else return true;
	};
	auto प्रक्षिप्तः=[समत्वम्](const char* अङ्कः)
	{return समत्वम्(अङ्कः,"ा")||समत्वम्(अङ्कः,"ि")||समत्वम्(अङ्कः,"ी")||समत्वम्(अङ्कः,"ु")||समत्वम्(अङ्कः,"ू")||समत्वम्(अङ्कः,"ृ")||समत्वम्(अङ्कः,"ॄ")||
		समत्वम्(अङ्कः,"ॢ")||समत्वम्(अङ्कः,"ॣ")||समत्वम्(अङ्कः,"े")||समत्वम्(अङ्कः,"ै")||समत्वम्(अङ्कः,"ो")||समत्वम्(अङ्कः,"ौ");};
	const int अनुदात्तलक्षणम् = -1;
	const int स्वरितलक्षणम् = -2;
	const int स्वरलक्षणम् = -3;
	const int मौनलक्षणम् = -7;
	while(*पाठः!='\0')
	{
		if(*पाठः>=0){पाठः++;continue;}
		वर्णः उपस्थितः;
		if(समत्वम्(पाठः,"॒"))
			स्वराः.push_back(अनुदात्तलक्षणम्);
		else if(समत्वम्(पाठः,"॑"))
			स्वराः.push_back(स्वरितलक्षणम्);
		if(!लक्ष्यः(पाठः,उपस्थितः)){पाठः+=3;continue;}
		if(अधिकारः(उपस्थितः,वर्गीयः)||अधिकारः(उपस्थितः,उष्मा)||अधिकारः(उपस्थितः,अन्तःस्थः))
		{
			if(*(पाठः+3)=='\0'||*(पाठः+3)>=0){वर्णाः.push_back(उपस्थितः);वर्णाः.push_back(अत्);}
			else if(समत्वम्(पाठः+3,"्")){वर्णाः.push_back(उपस्थितः);पाठः+=3;}
			else if(प्रक्षिप्तः(पाठः+3))वर्णाः.push_back(उपस्थितः);
			else {वर्णाः.push_back(उपस्थितः);वर्णाः.push_back(अत्);}
		}
		else वर्णाः.push_back(उपस्थितः);
		if(अधिकारः(वर्णाः.back(), स्वरः)) {
			if(वर्णाः.size()>1 && अधिकारः(*std::prev(वर्णाः.end(),2), स्वरः)) {
				वर्णाः.insert(std::prev(वर्णाः.end(),1), लघुमौनम्);
			}
			स्वराः.push_back(स्वरलक्षणम्);
		}
		else if(वर्णाः.back()==मौनम्)
			स्वराः.push_back(मौनलक्षणम्);
		पाठः+=3;
	}
	const int उदात्तः = -4;
	const int अनुदात्तः = -5;
	const int स्वरितः = -6;
	int गतिः = उदात्तः;
	for(auto लक्षणपदम्=स्वराः.begin(); लक्षणपदम्!=स्वराः.end(); ++लक्षणपदम्) {
		auto const पश्चिमम् = std::next(लक्षणपदम्, 1);
		if(*लक्षणपदम्==मौनलक्षणम्)
			गतिः=उदात्तः;
		else if(*लक्षणपदम्==स्वरलक्षणम् && (पश्चिमम्==स्वराः.end() || *पश्चिमम्==स्वरलक्षणम् || *पश्चिमम्==मौनलक्षणम्))
			*लक्षणपदम् = गतिः;
		else if(*लक्षणपदम्==अनुदात्तलक्षणम्) {
			*std::prev(लक्षणपदम्, 1)=अनुदात्तः;
			गतिः=उदात्तः;
		}
		else if(*लक्षणपदम्==स्वरितलक्षणम्) {
			*std::prev(लक्षणपदम्, 1)=स्वरितः;
			गतिः=अनुदात्तः;
		}
	}
	
	स्वराः.erase(std::remove_if(स्वराः.begin(), स्वराः.end(), [](auto const स्वरः){
		return स्वरः==स्वरलक्षणम्||स्वरः==स्वरितलक्षणम्||स्वरः==अनुदात्तलक्षणम्||स्वरः==मौनलक्षणम्;
	}), स्वराः.end());
	for(auto const& i:स्वराः){
		//printf("%s", [](auto const x){return x==उदात्तः?"u":x==स्वरितः?"s":"a";}(i));
	}
	गतिः = स्वराः.front()==अनुदात्तः?0:2;
	auto वर्णपदम्=वर्णाः.begin();
	auto स्वरपदम्=स्वराः.begin();
	if(अधिकारः(वर्णाः.front(),स्वरः)) {
		गतिः=स्वराः.front()==उदात्तः?2:0;
		स्वरक्रमः.push_back(गतिः);
		वर्णपदम्++;स्वरपदम्++;
	}
	while(वर्णपदम्!=वर्णाः.end()) {
		auto const पश्चिमम्=std::next(वर्णपदम्, 1);
		if(पश्चिमम्==वर्णाः.end() || !अधिकारः(*पश्चिमम्, स्वरः))
			स्वरक्रमः.push_back(गतिः);
		else {
			auto const पश्चिमस्वरः=*(स्वरपदम्++);
			if(पश्चिमस्वरः==अनुदात्तः) {
				स्वरक्रमः.push_back(0);
				गतिः=0;
			}
			else {
				स्वरक्रमः.push_back(2);
				गतिः=पश्चिमस्वरः==उदात्तः?2:0;
			}
		}
		वर्णपदम्++;
	}
	if(वर्णाः.back()==मौनम्)
		स्वरक्रमः.back()=स्वरक्रमः.front();
	//printf("\n");
	for(auto const&i:स्वरक्रमः) {
		//printf("%d", i);
	}
	return std::make_pair(वर्णाः, स्वरक्रमः);
}

int main(int argc,char *argv[])
{
	[[maybe_unused]]char वर्णमाला[]="अ। आ। इ। ई। उ। ऊ। ऋ। ॠ। ऌ। ॡ। ए। ऐ। ओ। औ। अं। अः। क। ख। ग। घ। ङ। च। छ। ज। झ। ञ। ट। ठ। ड। ढ। ण। त। थ। द। ध। न। प। फ। ब। भ। म। य। र। ल। व। श। ष। स। ह।",
		नर्मदादर्शनम्[]="न र्म दा द र्श न ङ्ग ङ्गा स्ना न स म फ ल मा हु स्त स्मा न्न र्म दा द र्श न ङ्कु र्या द थ त दु पा य यु प न्य स्य ते त द र्थ म्बा न्ध वै र्गु रु ज ने न च स ह म ध्य प्र दे श स्यो म रि या ज न प दा न्त र्ग तं वी र सिं ह पु र म्प्रा त र नु प्रा प्नु या त्त तः प ञ्चा श ज्ज ना ना न्न य ने श क्त ण्डि डो री पु री मु द्दि श्य प्र या तं या न मा रो हे द्या न मा रु ह्य त त्र बा न्ध वा न्ना नु स रे द थ य त्रा पि नि र्ज नं वा ता य न न्दृ श्ये त त त्र त्व रि त मा सी ता ध्व नि हि व न गि रि स रः पु लि न्द प ल्ली ना न्द र्श न म्बा न्ध व ज ल्पा द ति रि च्य ते त तो या ने न दू र म ध्वा न ङ्ग त्वा डि डो री म प्र ति प द्य जो गी टि क रि या या न्ना म ग्रा मे ति क्रा न्ते न र्म दा म न ति क्र म्यो त्त रे ण से तुं या ना द व रो हे त्से तो र्वा म त स्ती र्थ म स्ति त तो न दी न्द क्षि णे कृ त्वा प द्भ्या ङ्ग च्छे त्ती र्था न्त स्थ म्मा तृ कु टी र न्ना मा श्र म प द न्त त्रै को म हा त्मा नि व स ति यो भ ज ने न च भो ज ने न चा ग ता नां शु श्रू ष णे न च का ल न्न य ति त त स्त स्मि न्ना श्र मे न र्म दा न्द र्श न्द र्शं सु खं व से द थ म हा त्मा बा न्ध वा न्त रे स वि शे षं स्नि ह्ये च्चे दी र्ष्या न्न कु र्या द थ य द्य पि द र्श न मा त्रे ण फ ल प्रा प्ति रु क्ता त था पि न र्म दा यां स्ना ने दो षो न वि द्य ते था प्सु पू र्वं स्ना त ञ्चे द ह म्पू र्वि क यो द क म व गा हे ता न्य था बा न्ध वां श्चो द ये त्ते प्य न्यो न्य मी क्षे रं श्चे न्नि र्भी का न्पु लि न्द शि शूं स्त र तो दृ ष्ट्वा भ य म प नु दे त्त त्रा पा मु च्छृ ङ्ख ल त्वा द्ग्रा ह भ य न्ना स्ति कृ ष्ण क र्का स्तु ब ह व स्स न्ति न र्म दा त स्मि न्प र्व त म ये स्थ ले ल्प तो या प्रा ये ण व र्षा का ले तु वे ग व ती जा य ते य दा तु जा नु द ध्नः प्र वा ह स्त दा क ति प या नि प दा नि न दी म ध्य म्प्र ति ग त्वा स म्य ग वे क्ष्य य त्र क र्का न स्यु रि त्या सी ता थ मू र्धा भि षे का र्थ न्त ल स्थि ते न दृ ढे ना श्म ना त्मा न म व ष्ट भ्य स्रो तो भि मु खं स्थि त्वा ह स्ता भ्या म श्म न्या कृ ष्य नि म ज्ज्य प्रा णा न्नि य म्य त ले सं वि शे त्त दा श्मा न न्न प रि त्य जे त्प रि त्य क्ते तु म ह तीं हा नि मा त्म नो जा नी या द थ प रि भ व त्सु प्रा णे षू न्म ज्जे दे व न्त्रिः कु र्या द था श्मा तु य दि स्था ना च्च ले द्ध स्तं व्र ण ये द्वा चे द श्म भ्रा न्त्या क र्क ङ्गृ ही त ञ्जा नी या द वि चा र्य त म न्य त्र क्षि पे च्चा थ व्र णो प चि ते ष्व पि ह स्त पा दे ष्वा का र न्नि गू हे त्त तो य थे ष्ट ङ्क्री डि त्वो त्त रे द था ने न वि धि ना प्र ति दि न म्प्रा तः का लं या प ये द थ सा य न्तु प रि त श्च रे त्त त्र न द्या अ प रे ती रे द क्षि ण तो न दी ङ्कृ त्वा कि ञ्चि द्दू र ङ्ग त्वा गो स्वा मि ग्रा म स न्नि धा ने बि हा र प्र दे शे ल ब्ध ज न्म न स्स त्य स्य ना म म हा त्म न आ श्र म आ गि रि शि ख रं वि स्ती र्णे स र्व सा ध नो पे ते र्ह णा म धि ग च्छे द थ वो त्त रे ती र ए व या द वा ना ङ्ग्रा म स न्नि धा न उ प व ने र मे त वि वि धा न्या म्रा दी नि व न स म्भ वा नि स्वा दू नि फ ला न्य श्नी या दे वं सु खे न ने यः का ल स्त स्मि न्प्र दे शे थ य दा तु प र्व ते षु व र्षा का र णा न्न द्या म धि क ङ्गा म्भी र्य म्भ वे त्त दा ति त रे ण स्ना न म भि रो च ये द थ ब हु धा गु रु ज नं सा न्त्व यि त्वा व त रे त्त तः प्र ति कू ला नु कू ल प्र वा हा ना व र्त्तां श्च जा नी या द्वि दि त्वा सु खे न शी घ्र गा मि न म्प्र वा ह मा रु ह्य वि प्र कृ ष्टा न्न द्यु द्दे शां श्च रे द था प्ला व का ले पि न द्या मे व स्ना या न्न हि वि म लो प्य गा रे स्ना तो न दी ष्णा ना म्म ध्ये क था प्र स ङ्गे षु शो भ ते थै वं य था व का शं सु खा नु भ वे न न र्म दा द र्श ने न च व र्ते त ।",
		शिवनमस्कारः[]="ओंनमश्शिवाय्",
		पञ्चतन्त्रम्[]="तद्यथानुश्रूयते। अस्ति दाक्षिणात्ये जनपदे महिलारोप्यन्नाम नगरम्। तत्र सकलार्थिसार्थकल्पद्रुमः प्रवरमुकुटमणिमरीचिमञ्जरीचर्चितचरणयुगलस्सकलकलापारङ्गतोमरशक्तिर्नाम राजा बभूव। तस्य त्रयः पुत्राः परमदुर्मेधसो बहुशक्तिरुग्रशक्तिरनन्तशक्तिश्चेति नामानो बभूवुः।",
		वनकथा[]="वर्षर्तुस्समुपस्थितः। अधुनाहरिणेभ्ययुपलप्स्यन्तेनवशाद्वलानि। व्याघ्रोपिचिन्तामुक्तोभविष्यति।",
		नारायणीयम्[]="सान्द्रानन्दावबोधात्मकमनुपमितङ्कालदेशावधिभ्यान्निर्मुक्तन्नित्यमुक्तन्निगमशतसहस्रेणनिर्भास्यमानम्। अस्पष्टन्दृष्टमात्रेपुनरुरुपुरुषार्थात्मकम्ब्रह्मतत्त्वन्तत्तावद्भातिसाक्षाद्गुरुपवनपुरेहन्तभाग्यञ्जनानाम्।",
		रामायणम्[]="रा॒मस्य भा॒र्या॑ सी॒ता वन॑ङ् ग॒ता।",
		मनुचरितम्[]="मन॑वे ह॒ वै प्रा॒तः। अ॒व॒नेग्य॑म् उद॒कम् आज॑ह्रु॒र् यथे॒दम् पा॒णिभ्या॑म् अव॒नेज॑नाया॒हर॑न्त्ये॒वं तस्या॑व॒नेनि॑जानस्य॒ मत्स्यः॑ पा॒णी आपे॑दे।";

	auto वर्णस्वराः=वर्णनिर्णयः("ततस्तमक्षोभ्यबलं लङ्काधिपतये चराः।   सुवेले राघवं शैले निविष्टं प्रत्यवेदयन् ॥ 6.31.1  चाराणां रावणः श्रुत्वा प्राप्तं रामं महाबलम्।   जातोद्वेगोऽभवत् किञ्चित् सचिवानिदमब्रवीत् ॥ 6.31.2  मन्त्रिणः शीघ्रमायान्तु सर्वे वै सुसमाहिताः।   अयं नो मन्त्रकालो हि सम्प्राप्त इति राक्षसाः ॥ 6.31.3  तस्य तच्छासनं श्रुत्वा मन्त्रिणोऽभ्यागमन् द्रुतम्।   ततः स मन्त्रयामास सचिवै राक्षसैः सह ॥ 6.31.4  मन्त्रयित्वा स दुर्धर्षः क्षमं यत् समनन्तरम्।   विसर्जयित्वा सचिवान् प्रविवेश स्वमालयम् ॥ 6.31.5  ततो राक्षसमाहूय विद्युज्जिह्वं महाबलम्।   मायाविदं महामायः प्राविशद्यत्र मैथिली ॥ 6.31.6  विद्युज्जिह्वं च मायाज्ञमब्रवीद्राक्षसाधिपः।   मोहयिष्यावहे सीतां मायया जनकात्मजाम् ॥ 6.31.7  शिरो मायामयं गृह्य राघवस्य निशाचर।   त्वं मां समुपतिष्ठस्व महच्च सशरं धनुः ॥ 6.31.8  [दर्शयामास तां मायां सुप्रयुक्तां स रावणे।] तस्य तुष्टोऽभवद्राजा प्रददौ च विभूषणम् ॥ 6.31.9  अशोकवनिकायां तु सीतादर्शनलालसः।   नैर्ऋतानामधिपतिः संविवेश महाबलः ॥ 6.31.10  ततो दीनामदैन्यार्हां ददर्श धनदानुजः।   अधोमुखीं शोकपरामुपविष्टां महीतले ॥ 6.31.11  भर्तारमेव ध्यायन्तीमशोकवनिकां गताम्।   उपास्यामानां घोराभी राक्षसीभिरितस्ततः * ॥ 6.31.12  उपसृत्य ततः सीतां प्रहर्षं नाम कीर्तयन्।   इदं च वचनं धृष्टमुवाच जनकात्मजाम् ॥ 6.31.13  सान्त्व्यमाना मया भद्रे यमुपाश्रित्य वल्गसे।   खरहन्ता स ते भर्ता राघवः समरे हतः ॥ 6.31.14  छिन्नं ते सर्वतो मूलं दर्पस्ते विहतो मया।   व्यसनेनात्मनः सीते मम भार्या भविष्यसि ॥ 6.31.15  विसृजेमां मतिं मूढे किं मृतेन करिष्यसि।   भवस्व भद्रे भार्याणां सर्वासामीश्वरी मम ॥ 6.31.16  अल्पपुण्ये निवृत्तार्थे मूढे पण्डितमानिनि।   शृणु भर्तृवधं सीते घोरं वृत्रवधं यथा ॥ 6.31.17  समायातः समुद्रान्तं मां हन्तुं किल राघवः।   वानरेन्द्रप्रणीतेन बलेन महता वृतः ॥ 6.31.18  स निविष्टः समुद्रस्य पीड्य तीरमथोत्तरम्।   बलेन महता रामो व्रजत्यस्तं दिवाकरे ॥ 6.31.19  अथाध्वनि परिश्रान्तमर्धरात्रे स्थितं बलम्।   सुखसंसुप्तमासाद्य चारितं प्रथमं चरैः ॥ 6.31.20  तत्प्रहस्तप्रणीतेन बलेन महता मम।   बलमस्य हतं रात्रौ यत्र रामः सलक्ष्मणः ॥ 6.31.21  पट्टिशान् परिघांश्चक्रान् दण्डान् खड्गान् महायसान्।   बाणजालानि शूलानि भास्वरान् कूटमुद्गरान् ॥ 6.31.22  यष्टिश्च तोमरान् शक्तीश्चक्राणि मुसलानि च।   उद्यम्योद्यम्य रक्षोभिर्वानरेषु निपातिताः ॥ 6.31.23  अथ सुप्तस्य रामस्य प्रहस्तेन प्रमाथिना।   असक्तं कृतहस्तेन शिरश्छिन्नं महासिना ॥ 6.31.24  विभीषणः समुत्पत्य निगृहीतो यदृच्छया।   दिशः प्रव्राजितः सर्वैर्लक्ष्मणः प्लवगैः सह ॥ 6.31.25  सुग्रीवो ग्रीवया सीते भग्नया प्लवगाधिपः।   निरस्तहनुकः शेते हनुमान् राक्षसैर्हतः ॥ 6.31.26  जाम्बवानथ जानुभ्यामुत्पतन्निहतो युधि।   पट्टिशैर्बहुभिश्छिन्नो निकृत्तः पादपो यथा ॥ 6.31.27  निश्वसन्तौ रुदन्तौ च रुधिरेण परिप्लुतौ।   असिना व्यायतौ छिन्नौ मध्ये ह्यरिनिषूदनौ ॥ 6.31.28  अनुतिष्ठति मेदिन्यां पनसः पनसो यथा ॥ 6.31.29  नाराचैर्बहुभिश्छिन्नः शेते दर्यां दरीमुखः।   कुमुदस्तु महातेजा निष्कूजः सायकैः कृतः ॥ 6.31.30  अङ्गदो बहुभिश्छिन्नः शरैरासाद्य राक्षसैः।   पतितो रुधिरोद्गारी क्षितौ निपतिताङ्गदः ॥ 6.31.31  हरयो मथिता नागै रथजातैस्तथाऽपरे।   शायिता मृदिताश्चाश्वैर्वायुवेगैरिवाम्बुदाः ॥ 6.31.32  प्रहृताश्चापरे त्रस्ता हन्यमाना जघन्यतः।   अभिद्रुतास्तु रक्षोभिः सिंहैरिव महाद्विपाः ॥ 6.31.33  सागरे पतिताः केचित् केचिद्गगनमाश्रिताः।   ऋक्षा वृक्षानुपारूढा वानरीं वृत्तिमाश्रिताः ॥ 6.31.34  सागरस्य च तीरेषु शैलेषु च वनेषु च।   पिङ्गलास्ते विरूपाक्षैर्बहुभिर्बहवो हताः ॥ 6.31.35  एवं तव हतो भर्ता ससैन्यो मम सेनया।   क्षतजार्द्रं रजोध्वस्तमिदं चास्याहृतं शिरः ॥ 6.31.36  ततः परमदुर्धर्षो रावणो राक्षसाधिपः।   सीतायामुपशृण्वन्त्यां राक्षसीमिदमब्रवीत् ॥ 6.31.37  राक्षसं क्रूरकर्माणं विद्युज्जिह्वं त्वमानय।   येन तद्राघवशिरः सङ्ग्रामात् स्वयमाहृतम् ॥ 6.31.38  विद्युज्जिह्वस्ततो गृह्य शिरस्तत् सशरासनम्।   प्रणामं शिरसा कृत्वा रावणस्याग्रतः स्थितः ॥ 6.31.39  तमब्रवीत्ततो राजा रावणो राक्षसं स्थितम्।   विद्युज्जिह्वं महाजिह्वं समीपपरिवर्त्तिनम् ॥ 6.31.40  अग्रतः कुरु सीतायाः शीघ्रं दाशरथेः शिरः।   अवस्थां पश्चिमां भर्तुः कृपणा साधु पश्यतु ॥ 6.31.41  एवमुक्तं तु तद्रक्षः शिरस्तत् प्रियदर्शनम्।   उपनिक्षिप्य सीतायाः क्षिप्रमन्तरधीयत ॥ 6.31.42  रावणश्चापि चिक्षेप भास्वरं कार्मुकं महत्।   त्रिषु लोकेषु विख्यातं सीतामिदमुवाच च ॥ 6.31.43  इदं तत्तव रामस्य कार्मुकं ज्यासमायुतम्।   इह प्रहस्तेनानीतं हत्वा तं निशि मानुषम् ॥ 6.31.44  स विद्युजिह्वेन सहैव तच्छिरो धनुश्च भूमौ विनीकीर्य रावणः।   विदेहराजस्य सुतां यशस्विनीं ततोऽब्रवीत्तां भव मे वशानुगा ॥ 6.31.45 ");//आपो॒ वा अ॒ग्नेरा॒यत॑नम् । आ॒यत॑नवान् भवति । य ए॒वं वेद॑ ।");
	std::list<वर्णः> क्रमः=वर्णस्वराः.first;
	std::list<int> स्वरक्रमः=वर्णस्वराः.second;
	std::list<वर्णः>::iterator स्थानम्=क्रमः.begin();
	std::list<int>::iterator स्वरस्थानम्=स्वरक्रमः.begin();
	auto क्रमणम्=[&क्रमः,&स्थानम्,&स्वरक्रमः,&स्वरस्थानम्]()
	{
		वर्णः उपस्थितः=*स्थानम्;
		int स्वरः=*स्वरस्थानम्;
		स्थानम्++;
		स्वरस्थानम्++;
		if(स्थानम्==क्रमः.end()){स्थानम्=क्रमः.begin();स्वरस्थानम्=स्वरक्रमः.begin();}
		return std::make_pair(उपस्थितः,स्वरः);
	};
	वाचकम् मुखम्({(std::pair<वर्णः,int> (*)(void*))([](void* d){return (*static_cast<decltype(क्रमणम्)*>(d))();}),&क्रमणम्});
	
	bool परोक्षम्=false;
	for(int क्रमः=0;क्रमः<argc;क्रमः++)
		if(argv[क्रमः][0]=='0')परोक्षम्=true;
	if(परोक्षम्)
	{
		while(true)
		{
			float गृहीतम्=मुखम्.ग्रहणम्();
			fwrite(&गृहीतम्,sizeof(float),1,stdout);
		}
		return 0;
	}
	
	auto MyAudioCallback=[](void *userdata, Uint8 *stream, int len)
	{
		clock_t आरम्भकालः=clock();
		while(len)
		{
			*((float*)stream)=((वाचकम्*)userdata)->ग्रहणम्();
			stream+=sizeof(float);
			len-=sizeof(float);
		}
		//clock_t अन्तकालः=clock();
		//double अवधिः=double(अन्तकालः-आरम्भकालः);
		//std::cout<<"ग्रहणावधिः -  "<<अवधिः/CLOCKS_PER_SEC<<std::endl;
	};
	
	if (SDL_Init(SDL_INIT_AUDIO|SDL_INIT_VIDEO) < 0)
			return 1;
	
	SDL_Window *दर्शनम्=SDL_CreateWindow(
        "वाचकम्",                  // window title
        SDL_WINDOWPOS_UNDEFINED,           // initial x position
        SDL_WINDOWPOS_UNDEFINED,           // initial y position
        480,                               // width, in pixels
        480,                               // height, in pixels
        0                  // flags - see below
    );
  
  SDL_Renderer* चित्रकारः=SDL_CreateRenderer(दर्शनम्,-1,0);
  SDL_RenderClear(चित्रकारः);
  SDL_RenderPresent(चित्रकारः);
  
  SDL_AudioSpec want, have;
	SDL_AudioDeviceID dev;

	SDL_memset(&want, 0, sizeof(want)); /* or SDL_zero(want) */
	want.freq = मुखम्.नैमिषिकानि;
	want.format = AUDIO_F32;
	want.channels = 1;
	want.samples = मुखम्.नैमिषिकानि;
	want.callback = MyAudioCallback; /* you wrote this function elsewhere -- see SDL_AudioSpec for details */
	want.userdata=&मुखम्;
	
	dev = SDL_OpenAudioDevice(NULL, 0, &want, &have, 0);
	if (dev == 0) {
	    return 1;
	}
	SDL_PauseAudioDevice(dev, 0); /* start audio playing. */
	
	bool वर्त्तनम्=true;
	while (वर्त्तनम्) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        /* handle your event here */
    	if(event.type==SDL_KEYDOWN)
      {
				if(event.key.keysym.sym == SDLK_ESCAPE)वर्त्तनम्=false;
			}
    }
		SDL_Delay(16);
    /* do some other stuff here -- draw your app, etc. */
	}
	SDL_DestroyWindow(दर्शनम्);
	SDL_CloseAudioDevice(dev);
	SDL_Quit();
	return 0;
}
