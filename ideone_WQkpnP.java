public class Main{
	
	static Queue[] player = new Queue[2];
	
	//static Queue player[0] = new Queue(); 
	//static Queue player[1] = new Queue();
	
	static Stack p1war = new Stack(); //stores facedown cards during war
	static Stack p2war = new Stack();
	
	public static void deal(){
		Deck deck = new Deck();
		deck.shuffle();
		for (int i = 0; i < 26; i++) {
			player[0].put(deck.getCard());
			player[1].put(deck.getCard());
		}
	}
	
	public static void war(){
		System.out.println("WAR!");
		if(player[0].size()<4){ //making sure player[0] has 1 face-up card for war
			for(int i=0;i<player[0].size()-1;i++){
				p1war.put(player[0].get());
			}
		}
		else{
			for(int i=0;i<3;i++){
				p1war.put(player[0].get());
			}
		}
		
		if(player[1].size()<4){ //making sure player[1] has 1 face-up card for war
			for(int i=0;i<player[1].size()-1;i++){
				p2war.put(player[1].get());
			}
		}
		else{
			for(int i=0;i<3;i++){
				p2war.put(player[1].get());
			}
		}
		System.out.println(((Card) player[0].peek()).getSymbol()+" versus "+
				((Card)player[1].peek()).getSymbol());
		if(((Card) player[0].peek()).compareTo((Card) player[1].peek())>0){ //player 1 wins war
			player[0].put(player[0].get());
			player[0].put(player[1].get());
			while(p1war.size()>0) //distributes face-down cards to winner
				player[0].put(p1war.get());
			while(p2war.size()>0)
				player[0].put(p2war.get());
			System.out.println("Player 1 has "+player[0].size()+", Player 2 has "+player[1].size()+".");
		}
		else if(((Card) player[0].peek()).compareTo((Card) player[1].peek())<0){ //player 2 wins war
			player[1].put(player[0].get());
			player[1].put(player[1].get());
			while(p1war.size()!=0) //distributes face-down cards to winner
				player[1].put(p1war.get());
			while(p2war.size()!=0)
				player[1].put(p2war.get());
			System.out.println("Player 1 has "+player[0].size()+", Player 2 has "+player[1].size()+".");
		}
		else{//in the case of a back to back war
			if(player[0].size()>1) //making sure player1 has atleast 1 faceup card
				p1war.put(player[0].get()); 
			if(player[1].size()>1) //making sure player2 has atleast 1 faceup card
				p2war.put(player[1].get());
			war();
		}
	}
	
	public static void playRound(){
		System.out.println(((Card)player[0].peek()).getSymbol()+" versus "+
				((Card)player[1].peek()).getSymbol());
		if(((Card)player[0].peek()).compareTo((Card)player[1].peek())>0){ //if player 1 wins round
			player[0].put(player[0].get());
			player[0].put(player[1].get());
			System.out.println("Player 1 has "+player[0].size()+", Player 2 has "+player[1].size()+".");
		}
		else if(((Card)player[1].peek()).compareTo((Card)player[0].peek())>0){ //if player 2 wins round
			player[1].put(player[1].get());
			player[1].put(player[0].get());
			System.out.println("Player 1 has "+player[0].size()+", Player 2 has "+player[1].size()+".");
		}
		else{ //if tied, then war
			if(player[0].size()>1) //making sure player1 has atleast 1 faceup card
				p1war.put(player[0].get()); 
			if(player[1].size()>1) //making sure player2 has atleast 1 faceup card
				p2war.put(player[1].get());
			war();
		}
	}

	public static void playWar(){
		deal(); 
		while(player[0].size()!=0 && player[1].size()!=0){ //play rounds until someone wins
			playRound();
		}
		if(player[0].size()==0){
			System.out.println("Player 2 Wins!");
		}
		else if(player[1].size()==0){
			System.out.println("Player 1 Wins!");
		}
	}
	
	public static void main(String[] args){
		player[0] = new Queue();
		player[1] = new Queue();
		playWar();
	}
}