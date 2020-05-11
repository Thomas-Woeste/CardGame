/* Author: Thomas Woeste
 * Program: cards.cpp
 * Date: 1/25/2020
 * Purpose: The purpose of this file is to play a card game where players roll die to see where their cards go.
 *          Players win by either having the lowest weight at the end of the given turns or a player runs out 
 *          of cards. 
 */

#include <iostream>
#include <string> 
#include <fstream>
#include "dequeue.h"

using namespace std;

//Takes in a random number from standard input and changes the number to be a random number from 1 to the range inputed into the function 
int rollDie (int range){
    int randomLargeNumber;
    int answer;

    cin >> randomLargeNumber;
    answer = (randomLargeNumber % range) + 1;
    return answer;
} //rollDie 

//accpeting cards
Dequeue acceptCard(Dequeue deck, int data) {
   deck.insertFrontDequeue(data);

   return deck;
} //acceptCard

//discarding a card 
int discardCard(int frontOrRear, Dequeue deck) {
    int cardValue;

    //Remove from front of deck
    if(frontOrRear == 1) {
        cardValue = deck.deleteFrontDequeue();
    }
    else {
        cardValue = deck.deleteRearDequeue();
    }

    return cardValue;
} //discardCard

const int ARGUMENTS = 4;

int main(int argc, char* argv[]){
	if(argc != ARGUMENTS){
		cout << "Warning: need exaclty"  << ARGUMENTS - 1 << " command line arguments." << endl;

		return 1;
	}

    const int NUMPLAYERS = atoi(argv[1]);
    const int NUMCARDS = atoi(argv[2]);
    const int NUMTURNS = atoi(argv[3]);
    

    //special error cases
	if(NUMPLAYERS == 0){
		cout << "The number of players cannot be 0" << endl;

		return 1;
	}
    else if(NUMCARDS == 0){
        cout << "The number of cards cannot be 0" << endl;

        return 1;
    }
    else if (NUMTURNS == 0){
        cout << "The number of turns cannot be 0" << endl;

        return 1;
    }

    //Build the players decks
    Dequeue playersDecks[NUMPLAYERS];

    for(int currPlayer = 0; currPlayer < NUMPLAYERS; currPlayer++) {
        for(int currCard = NUMCARDS; currCard >= 1; currCard--){
            playersDecks[currPlayer].insertFrontDequeue(currCard);
        }
    }
    
    //play the game
    int currTurn = 1;
    int hasWonCards = 0;
    int playerWon = 0;
    while(currTurn <= NUMTURNS && hasWonCards == 0) {
        int advPlayer;
        advPlayer = rollDie(NUMPLAYERS);
     
        int frontOrRear = rollDie(2);
        int removedData = discardCard(frontOrRear, playersDecks[advPlayer - 1]);
    
        int acceptPlayer = rollDie(NUMPLAYERS);
        playersDecks[acceptPlayer - 1] = acceptCard(playersDecks[acceptPlayer - 1], removedData);
        

        //output the turn
        string topOrBottom;
        if(frontOrRear == 1)
            topOrBottom = "top";
        else
            topOrBottom = "bottom";

        cout << "turn " << currTurn << ": player " << advPlayer << " sends a card to " << acceptPlayer << ", from " << topOrBottom << endl;
        
        //Checks to see if a player has won
        for(int i = 0; i < NUMPLAYERS; i++){
            cout << "\t player " << i+1 << ": weight: " << playersDecks[i].calcWeight() << endl;
            if (playersDecks[i].calcWeight() == 0) {
                hasWonCards = 1;
                playerWon = i+1;
            }
        }

        if(hasWonCards == 1) {
            cout << "Game is over; player " << playerWon << " has no cards left." << endl; 
        }
        currTurn += 1;
    } //while

    if(hasWonCards == 0) {
        int lowestWeight;
        int playerWeight;
        

        for(int player = 0; player < NUMPLAYERS; player++) {
            playerWeight = playersDecks[player].calcWeight();

            if(playerWeight < lowestWeight){
                lowestWeight = playerWeight;
                playerWon = player+1;
            }
        }
        cout << "Game is over; player " << playerWon << " has the lowest weight." <<endl; 
    }
            
    return 0;
} //main
