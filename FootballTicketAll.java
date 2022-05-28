import java.util.Scanner;
public class FootballTicketAll {
    public static void main(String args[]) {
        
        int age;
        char seat;
        double agePrice = 0;
        double price1;
        double seatPrice = 0;
        double price2;
        int numTicket;
        
        numTicket = numTicket();

        for(int i = 1; i <= numTicket; i++){
            age = getAge();
            seat = getSeat();
            price1 = agePrice(age);
            agePrice = agePrice + price1;
            price2 = seatPrice(seat);
            seatPrice = seatPrice + price2;
        }
        totalPrice(agePrice, seatPrice);

    }
    public static int numTicket(){
        int numTicket;
        Scanner in = new Scanner(System.in);
        System.out.print("Enter number of ticket : ");
        numTicket = in.nextInt();
        return numTicket;

    }
    
    public static int getAge(){
        int age;
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter age : ");
        age = sc.nextInt();
        return age;
    }
    
    public static char getSeat(){
        char seat;
        Scanner in = new Scanner(System.in);
        System.out.print("Enter seat [G][R][B][Y] : ");
        seat = in.next().charAt(0);
        return seat;
    }
    
    public static double agePrice(int age){
        final int PRICE_ADULT = 20, PRICE_STUDENT = 15, PRICE_CHILD = 5;
        double price1;
        
        if (age > 24){
            price1 = PRICE_ADULT * 0.9;
        }else if (age >= 13){
            price1 = PRICE_STUDENT * 0.9;
        }else{
            price1 = PRICE_CHILD * 0.9;
        }
        return price1;
    }
    
    public static double seatPrice(char seat){
        double price2 = 0;
        
        switch(seat){
            case 'G' :
            case 'g' : price2 = 20 * 0.75;
                       break;
            case 'R' :
            case 'r' : price2 = 10;
                       break;
            case 'B' :
            case 'b' : price2 = 7;
                       break;
            case 'Y' :
            case 'y' : price2 = 5;
                       break;
            default  : System.out.print("Invalid Seat!!!");
            
        }
        return price2;
    }
    public static void totalPrice(double agePrice, double seatPrice){
        double totalPrice;
        totalPrice = agePrice + seatPrice;
        System.out.print("Your total price ticket : RM" + String.format("%.2f" , totalPrice));
    }
    
}