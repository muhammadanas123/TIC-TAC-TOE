#include<iostream>
using namespace std;
class TICTACK
{
	private:
		int countX;
		int countO;
		int countD;
		char player;
	public:
		TICTACK()
		{
			countX=0;
			countO=0;
			countD=0;
			player='X';
		}
		void button();
		void declare();
		void fileX(int x);
		void fileO(int x);
		void fileD(int x);
		void fileDopen();
		void fileXopen();
		void fileOopen();
		void  toggleplayer();
		void displaystructure();
		void Gamemangment();
		void initializing();
		~ TICTACK()
		{
			countX=0;
			countO=0;
			countD=0;
			player=0;
		}
	
	
};
