#include <iostream>
#include "2048.h"
#include <iomanip>
#include <time.h>
#include <string>


 using namespace std;


   void game::draw()
    {
	system( "cls" );
	
	for( int y = 0; y < 4; y++ )
	{
	    cout << "+___________________________+" << endl << "| ";
	    for( int x = 0; x < 4; x++ )
	    {
		if(!board[x][y].val) 
			{
				cout << setw( 4 ) << " ";
		}
		else
			cout << setw( 4 ) << board[x][y].val;
		cout << " | ";
	    }
	    cout << endl;
	}
	cout << "+___________________________+" << endl << endl;
	cout<<"Score="<<score<<endl;
    }
    void game::play()
    {
	Newtile(); 
	while( 1==1 )
	{
	    if( workd= true )
			{
				Newtile();
		

				draw(); }
	    if( !ok ) break;
	    Input();
	}
	string end = "Game Over!";
	if( w= false )
	{ 
		end = "You won!";}
		cout << end << endl;
    }
    void game::Input()//User input and random number generation
    {
		char x; 
	workd = false;
	
	
	cout << "Press I for Up,K for Down,J for Left,L for Right \n\nKeep CAPS lock OFF\nYou can also enter multiple commands:\n "; 
	
	cin >> x;
	if (x=='i')
		work(U);
	else if (x=='j')
		work(L);
	else if (x=='k')
		work(D);
	else if (x=='l')
		work(R);

 
	for( int y = 0; y < 4; y++ )
	    for( int x = 0; x < 4; x++ )
		board[x][y].wall = false;
    }
    void game::Newtile()
    {
	for( int y = 0; y < 4; y++ )
	    for( int x = 0; x < 4; x++ )
		if( !board[x][y].val )
		{
		    unsigned int a, b;
		    do
		    {
				a = rand() % 4;
				b = rand() % 4; 
			}
		    while( board[a][b].val );
 
		    int s;
			s = rand() % 50;
		    if( s > 40 )
			{
				board[a][b].val = 4;// 1/5 chance of getting a tile valued 4 
			}
		    else board[a][b].val = 2;// 4/5 chance of getting a tile valued 2
		    if( move() )
				return;
		}
	ok = false;
    }
    bool game::move()
    {
	for( int y = 0; y < 4; y++ )
	    for( int x = 0; x < 4; x++ )
		if( !board[x][y].val )
			return true;
 
	for( int y = 0; y < 4; y++ )
	    for( int x = 0; x < 4; x++ )
	    {
		if( check( x + 1, y, board[x][y].val ) )
			return true;
		if( check( x - 1, y, board[x][y].val ) )
			return true;
		if( check( x, y + 1, board[x][y].val ) )
			return true;
		if( check( x, y - 1, board[x][y].val ) )
			return true;
	    }
	return false;
    }
   
	
	bool game::check( int x, int y, unsigned int v )
    {
	if( x >= 0 && x <= 3 && y >= 0 && y <= 3 )
		
			return true;
	return board[x][y].val == v;

    }
      void game::Hmovement( int x, int y, int d )
    {
	if( board[x + d][y].val && board[x + d][y].val == board[x][y].val && !board[x][y].wall && !board[x + d][y].wall  )
	{
	    board[x][y].val = 0;
	    board[x + d][y].val *= 2;
	    score += board[x + d][y].val;
	    board[x + d][y].wall = true;
	    workd = true;
	}
	else if( !board[x + d][y].val && board[x][y].val )
	{
	    board[x + d][y].val = board[x][y].val;
	    board[x][y].val = 0;
	    workd = true;
	}
	if( d > 0 ) {
		if( x + d < 3 )
			Hmovement( x + d, y,  1 );
	}
	else        { 
		if( x + d > 0 )
			Hmovement( x + d, y, -1 );
	
	}
    }
	void game::Vmovement( int x, int y, int d )
    {
	if( board[x][y + d].val && board[x][y + d].val == board[x][y].val && !board[x][y].wall && !board[x][y + d].wall )
	{
	    board[x][y].val = 0;
	    board[x][y + d].val *= 2;
	    score += board[x][y + d].val;
	    board[x][y + d].wall = true;
	    workd = true;
	}
	else if( !board[x][y + d].val && board[x][y].val )
	{
	    board[x][y + d].val = board[x][y].val;
	    board[x][y].val = 0;
	    workd = true;
	}
	if( d > 0 ) {
     if( y + d < 3 ) 
		Vmovement( x, y + d,  1 ); }
	else        { if( y + d > 0 ) Vmovement( x, y + d, -1 ); }
    }

    void game::work(Direction z)
    {
	switch( z )
	{
	    case U:
	    	for( int x = 0; x < 4; x++ )
		{
		    int y = 1;
		    while( y < 4 )
		    { 
				if( board[x][y].val )
					Vmovement( x, y, -1 );
				y++;
			}
		}
		break;
	    case D:
		for( int x = 0; x < 4; x++ )
		{
		    int y = 2;
		    while( y >= 0 )
		    {
				if( board[x][y].val )
					Vmovement( x, y, 1 );
				y--;
			}
		}
		break;
	    case L:
		for( int y = 0; y < 4; y++ )
		{
		    int x = 1;
		    while( x < 4 )
		    { 
				if( board[x][y].val )
					Hmovement( x, y, -1 );
				x++;
			}
		}
		break;
	    case R:
		for( int y = 0; y < 4; y++ )
		{
		    int x = 2;
		    while( x >= 0 )
		    {
				if( board[x][y].val )
			Hmovement( x, y, 1 );
			x--;
			}
		}
	}
    }
    
	

int main()
{
    game newgame; 
	newgame.play();
 system( "pause" );
 return 0;
}