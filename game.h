#define row 3
#define col 3
//ÉùÃ÷
void InitBoard(char board[row][col],int ROW,int COL );
void Displayboard(char board[row][col],int ROW,int COL);
void playermove(char board[row][col],int ROW,int COL);
void PCmove(char board[row][col],int ROW,int COL);
char iswin(char board[row][col],int ROW,int COL);
int isfull(char board[row][col],int ROW,int COL);