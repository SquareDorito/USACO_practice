public class Main{
	
	static Queue player1 = new Queue();
	static Queue player2 = new Queue();
	
	static Stack p1war = new Stack();
	static Stack p2war = new Stack();
	
	public static void deal(){
		Deck deck = new Deck();
		deck.shuffle();
		for (int i = 0; i < 26; i++) {
			player1.put(deck.getCard());
			player2.put(deck.getCard());
		}
	}
	
	public static void playRound(){
		if(((Card)player1.peek()).compareTo((Card)player2.peek())>0){
			System.out.println(((Card)player1.peek()).getSymbol()+" versus "+
				((Card)player2.peek()).getSymbol());
			player1.put((Card)player1.get());
			player1.put((Card)player2.get());
			System.out.println("Player 1 has "+player1.size()+", Player 2 has "+player2.size());
		}
		else if(((Card)player2.peek()).compareTo((Card)player1.peek())>0){
			System.out.println(((Card)player1.peek()).getSymbol()+" versus "+
				((Card)player2.peek()).getSymbol());
			player2.put((Card)player2.get());
			player2.put((Card)player1.get());
			System.out.println("Player 1 has "+player1.size()+", Player 2 has "+player2.size());
		}
		else{
			System.out.println(((Card)player1.peek()).getSymbol()+" versus "+
					((Card)player2.peek()).getSymbol());
			System.out.println("WAR!");
			if(player1.size()<4){
				for(int i=0;i<player1.size()-1;i++)
					p1war.put((Card) player1.get());
			}
			else{
				for(int i=0;i<3;i++)
					p1war.put((Card) player1.get());
			}
			if(player2.size()<4){
				for(int i=0;i<player2.size()-1;i++)
					p2war.put((Card) player2.get());
			}
			else{
				for(int i=0;i<3;i++)
					p2war.put((Card) player2.get());
			}	
			
			if(((Card)player1.peek()).compareTo((Card)player2.peek())>0){
				System.out.println(((Card)player1.peek()).getSymbol()+" versus "+
						((Card)player2.peek()).getSymbol());
				player1.put((Card)player1.get());
				player1.put((Card)player2.get());
				int length1=p1war.size();
				for(int i=0;i<length1;i++)
					player1.put((Card)p1war.get());
				int length2=p2war.size();
				for(int i=0;i<length2;i++)
					player1.put((Card)p2war.get());
				System.out.println("Player 1 has "+player1.size()+", Player 2 has "+player2.size());
			}
			else if(((Card)player2.peek()).compareTo((Card)player1.peek())>0){
				System.out.println(((Card)player1.peek()).getSymbol()+" versus "+
						((Card)player2.peek()).getSymbol());
				player2.put((Card)player1.get());
				player2.put((Card)player2.get());
				int length1=p1war.size();
				for(int i=0;i<length1;i++)
					player2.put((Card)p1war.get());
				int length2=p2war.size();
				for(int i=0;i<length2;i++)
					player2.put((Card)p2war.get());
				System.out.println("Player 1 has "+player1.size()+", Player 2 has "+player2.size());
			}
			else{
				playRound();
			}
		}
	}

	public static void playWar(){
		deal();
		while(player1.size()!=0 && player2.size()!=0){
			playRound();
		}
		if(player1.size()==0){
			System.out.println("Player 2 Wins!");
		}
		else if(player2.size()==0){
			System.out.println("Player 1 Wins!");
		}
	}
	
	public static void main(String[] args){
		playWar();
	}
}