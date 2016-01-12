#include <iostream>
using namespace std;

enum Direction {U,D,L,R};


class game
{
	private:
    bool ok, workd, w;
    unsigned int score;
    
    public:

	game()
	{
		ok= true;
		w= false;
		workd= true;
		score= 0;
	}
   

    void draw();
	 void Vmovement( int x, int y, int d );
    void Hmovement( int x, int y, int d );
    void Input();
	 void play();
    bool move();
    bool check( int x, int y, unsigned int v );
   void Newtile();
    void work(Direction d);
   };
class block
{
private:
	
public:
    block()
	{
		val=NULL;
		wall=false;
	}
    unsigned int val;
	
    bool wall;
	
};
block board[4][4];