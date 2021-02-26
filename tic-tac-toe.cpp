#include<iostream>

using namespace std;
   char current_mark; 
   int player;  
   char arr1[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};

void DrawBoard(){
  
  /*
  tic-tac-toe board look 
    1 | 2 |  3  
  ______________   
    4 | 5 |  6
  ______________
    7 | 8 | 9 
 */

    cout<<arr1[0][0]<<" "<<" | "<<arr1[0][1]<<" | "<<arr1[0][2]<<""<<endl;
    cout<<"____________\n";
    cout<<arr1[1][0]<<" "<<" | "<<arr1[1][1]<<" | "<<arr1[1][2]<<""<<endl;
     cout<<"____________\n";
     cout<<arr1[2][0]<<" "<<" | "<<arr1[2][1]<<" | "<<arr1[2][2]<<""<<endl;
 
}

//marker placing code
bool placemarker(int slot){
    int row;
    if(slot%3==0){
        row=(slot/3)-1;
        }

    else{
        row=slot/3;
       }

       int col;
       if(slot%3==0){
           col=2;
       }
       else
       {
           col=slot%3-1;
       }
 
 /*condition to check if arr1[row][col] have already 'X' or 'O' 
   if yes (i.e) that selected box doesnt have X and O it will filled with current_player_marker.
   else current_player will not able to fill  that area  which is already filled with X or O.
 */
 if(!(arr1[row][col]=='X' || arr1[row][col]=='O')) 
 {
     arr1[row][col]=current_mark;
      return true; 
      
      
 }
 else{
       return false;   
      
    } 

}

/* this int winner() function is used to check 
if player 1 or player2 has won or not
*/
int winner(){

 for(int i=0;i<3;i++){
     //row checkwin
     if(arr1[i][0]==arr1[i][1] && arr1[i][1]==arr1[i][2])return player;
      //column checkwin
      if(arr1[0][i]==arr1[1][i]&& arr1[1][i]==arr1[2][i])return player;

 }
 //diagonal checkwin
 if(arr1[0][0]==arr1[1][1]&& arr1[1][1]==arr1[2][2] ||arr1[0][2]==arr1[1][1]&& arr1[1][1]==arr1[2][0])return player;   

//it will return 0 if all  cases failed. 
 return 0; 
} 
// end of int winner() function 

  /*void swap_player_turn_marker()
   function is created to swap player's turn .  
  */
void swap_player_turn_marker(){
    /* This is used to check if current_mark of current_player is X or O. 
       if current_mark of player is X then after his/her turn the function
       void swap_player_turn_marker() function will be called so that it will swap
       player number and player marker

       example: if player 1 has choose marker X so after his/her turn 
       the swap_player_function_marker() will be  called 
       an thus it will swap player number and player marker 
       in this example case the next  player will be 2 and player marker will be 'O'. 
    */

    if(current_mark=='X'){
        current_mark='O';
        player=2;
    }
    else{
        current_mark='X';
        player=1;
    }

}

//end of void swap_player_turn_marker() function 

void game(){
    char marker_p1;
    cout<<"Player 1 please select the marker 'O' or 'X': ";
    cin>>marker_p1; 
    player=1;
    current_mark=marker_p1;
    DrawBoard();
    int player_won;
    for(int i=0;i<9;i++){
        cout<<"It's "<<player<<" player turn"<<"  select the slot which you want to place your selected marker: ";
         int slot;
         cin>>slot;
         //this is used to check that he/her has choose right option from 1 to 9 to place their marker.
         if(slot<1 ||slot>9){
             cout<<"Please enter correct slot number present on board.";
               i--;
               continue;
             }
           
         if(!placemarker(slot)){
               
             cout<<"Place is already ocuppied please mark your X/O on another slot"<<endl;
             i-=1;
             continue;
             /*continue keyword is used because 
             if iterator 'i' is decreased it will again 
             get incremented so after decrement it will continue instead of getting incremented
             */
           
         }
         
         /*player_won variable will hold integer value 
         which will be passed by int winner() function
          either it will return 1(i.e) TRUE or FALSE(0).
         */
         player_won=winner();
         /* here are two if condition to
          check if player 1 or player 2 has won
         */
         if(player_won==1){
            cout<<"Congratulations player 1 you have won the match!....."<<endl;
              break;
           }
         if(player_won==2)
         {cout<<"Congratulations player 2 you have won the match!....."<<endl;
          break;
          }
          /* if both if cases get failed
           swap_player_function()
            will be called which will
            swap player number and marker
          */
        swap_player_turn_marker();
         DrawBoard();  
         }

          // when nobody wins then if condition gets true          
        if(player_won==0)cout<<"That is a tie game."<<endl;      
    }
   
int main(){

    game();
    DrawBoard();
 
    
    return 0;
}
//Here code ends

//END OF TIC-TAC-TOE GAME IN C++.


