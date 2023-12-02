//Muhammad Umer Farooq 408786
//Muhammad Zikrullah Rehman 416430

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#include "ToDo.c"
#include "colorprint.c"
#include "Budgeter.c"
#include "Scheduler.c"

int tdlisttools();
int othertools();
int scheduler();
int GPA();
//int budgeter();
int qgenerator();

int main(){
	SetToDoTime();
	Getlist();
	system("cls");
	
	time_t t;
	time(&t);
	printgreen(ctime(&t));				//printing time


	char line1[] = "\nYour to-do list\n";
	char line2[] = "Your to do list has expired. Please Refresh it\n";
	
	
	printyellow(line1);					//printing to-do list header

	char dummy[7][20];					//dummy to-do list to check
	char print[20];
	char printnum[20] = "";
		
	int indx = 1;	
	int y = CompTime();
	if(y)
	{
		printHighRed(line2); //prints warning to reset ToDo list has expired
	}
	for(int i = 0; i < 100; i++){
		
		
		strcpy(print, ToDoList[i]);		//print the dummy
		if(strlen(print) != 0)
		{
			printf("    %d. ", (indx));		//print the number
			printpurple(print);
			indx++;
		}
			
	}
	
	printf("\n");
	
	printf("2. To-do list tools\n");		//prints the rest of the menu
	printf("3. Other tools\n");			
	printf("4. Scheduler\n");
	printf("5. Exit\n");
	char exitline[] = "Goodbye!!!";	//farewell statement
	
	int nextmenu; 
	
	scanf("%d", &nextmenu);				//takes input from user for which menu to go to
	
	switch(nextmenu){
		case 2:
			tdlisttools();
			return 0;
			break;
		case 3:
			othertools();
			return 0;
			break;
		case 4:
			scheduler();
			return 0;
			break;
		case 5:
			goto quit;
			
		default:
			main();
			return 0;
			break;
			
				
				
	}
	
	quit:
 		system("cls");
 		SaveEntry();
		printred(exitline);
		getchar();
		getchar();
		return 0;
	
}	

int tdlisttools(){
	//function that opens up to-do list tools
	system("cls");
	
	char line[] = "TodoList Tools\n\n";	
	printgreen(line);
	
	printf("1. Add item to to do list\n");
	printf("2. Remove item from to do list\n");
	printf("3. Reset To Do list\n");
	printf("4. Go back\n");
	
	int nextmenu;
	scanf("%d", &nextmenu);
	char dec[] = "Enter To-Do list entry: \n";
	switch(nextmenu){
		case 1:
			AddtdEntry(); //function that calls function from library. Created because of anomaly of using library function as is
			getchar();
			tdlisttools();
			return 0;
			break;
	
		case 2:
			RemovetdEntry(); //function that calls function from library. Created because of anomaly of using library function as is
			getchar();
			tdlisttools();
			return 0;
			break;		
		case 3:
			Resettd(); //function that calls function from library. Created because of anomaly of using library function as is
			getchar();
			tdlisttools();
			return 0;
			break;	
		case 4:
			main(); //returns back to main menu
			return 0;
			break;
		default:
			tdlisttools();
			return 0;
			break;	
				
			
	}
	return 0;
}
void Resettd() //resets to do list
{
		system("cls");
		ResetToDo();
		 SaveEntry();
		char ls1[] = "ToDoList has been reset\n";
		printgreen(ls1);
		getchar();
		

}
void RemovetdEntry() //removes entry from todo list
{
	int sent = 1;
	while(sent) // loop to make sure deletion index is not empty or out of bounds
	{
		system("cls");
		char dec[]= "Index entry to delete or enter -1 to exit: ";
		printyellow(dec);
		int x = 0;
		scanf("%d", &x);
		x--;
		if(strlen(ToDoList[x]) != 0)
		{
			DelEntry(x);
	
			SaveEntry();
			break;
		}
		else if(x == -1)
		{
			sent = 0;
			break;
		}
		else
		{
			system("cls");
			char ls[] = "entry is already empty\n";	
			printred(ls);
			getchar();
			getchar();
		}
	
	}
}
	

void AddtdEntry() //adds entry to do list
{
	system("cls");
			char dec[]= "Enter Entry: ";
			printyellow(dec);
			getchar();
			char buff[100];
			fgets(buff, 100, stdin);
			buff[strcspn(buff, "\n")] = 0;
			AddToDoEntry(buff);
			SaveEntry();
			getchar(); 
}

int scheduler(){
	//function that opens up scheduler
	system("cls");
	
	char line[] = "Scheduler tools\n";
	printgreen(line);
	char line1[] = "\n\nSchedule\n";
	printyellow(line1);
	int indx = 1;
	for(int i = 0; i < 100; i++) //prints items in schedule if not empty
	{
		if((int)Schedulelist[i] != 0)
		{
			if(CompSched(Schedulelist[i]) == 0)
			{
				time_t ptr = (time_t) Schedulelist[i];
				printf("%d.\t%s\t%s\n",indx, ScheduleItems[i], asctime(localtime(&ptr)));
				
			}
			else
			{
				time_t ptr = (time_t) Schedulelist[i];
				char dummy[100];
				strcpy(dummy,asctime(localtime(&ptr)));
				dummy[strcspn(dummy, "\n")] = 0;
				printf("%d.\t%s\t%s",indx, ScheduleItems[i], dummy);
				char line1[] = "\tSchedule has expired\n";
				printred(line1);
			}
			indx++;
			
		}
	}
	
	
	printf("\n1. Add Entry\n2. Delete Entry\n3. Go back\n");
	int nextmenu;
	scanf("%d", &nextmenu);
	
	switch(nextmenu){
		case 1:
			AddSchdEntry(); //function that calls function from library. Created because of anomaly of using library function as is
			getchar();
			scheduler();
			tdlisttools();
			return 0;
			break;
		case 2:
			DelSchdEntry(); //function that calls function from library. Created because of anomaly of using library function as is
			getchar();
			scheduler();
			return 0;
			break;
			
		case 3:
			main();
			return 0;
			break;
		default:
			scheduler(); //function that calls function from library. Created because of anomaly of using library function as is
			return 0;
			break;
			
	}
	return 0;
}
void AddSchdEntry() //adds entry to schedule
{
	system("cls");
	int Year, Day, Month, hour;
	char Schedule[100];
   
	char line1[] = "Add New Schedule\n";
	printyellow(line1);
	printf("Add Year: \n");
	scanf("%d", &Year);
	printf("\nAdd Month: \n");
	scanf("%d", &Month);
	printf("\nAdd Day: \n");
	scanf("%d", &Day);
	printf("\nAdd Hour: \n");
	scanf("%d", &hour);
	printf("\nEnter Schedule info: ");
	getchar();
	char buff[100];
	fgets(buff, 100, stdin);
	buff[strcspn(buff, "\n")] = 0;
	AddEntry(Day, Year, Month, hour, buff);
	saveEntry();
	getchar();
	
}

void DelSchdEntry() //deletes entry from schedule
{
	int sent = 1;
	while(sent) //while loop to prevent index from being out of bounds or already empty
	{
		system("cls");
		char dec[]= "Index entry to delete or enter -1 to exit: ";
		printyellow(dec);
		int x = 0;
		scanf("%d", &x);
		x--;
		if(((int) Schedulelist[x]) != 0)
		{
			DeleteEntry(x);
			saveEntry();
			break;
		}
		else if(x == -1)
		{
			sent = 0;
			break;
		}
		else
		{
			system("cls");
			char ls[] = "entry is already empty\n";	
			printred(ls);
			getchar();
			getchar();
		}
	
	}
	
}

int othertools(){
	//function that opens up list of other tools
	system("cls");
	
	char line[] = "OTHER TOOLS:\n\n";
	char line1[] = "1. GPA calculator\n";
	char line2[] = "2. Budgeter\n";
	char line3[] = "3. Quote Generator\n";
	char line4[] = "4. Go back\n";
	
	printyellow(line);
	printred(line1);
	printred(line2);
	printred(line3);
	printred(line4);
	
	int nextmenu;
	scanf("%d", &nextmenu);
	
	switch(nextmenu){
		case 1:
			GPA();
			return 0;
			break;
		case 2:
			budgeter();
			othertools();
			return 0;
			break;
		case 3:
			qgenerator();
			return 0;
			break;
		case 4:
			main();
			return 0;
			break;
	}
	return 0;
}

int GPA(){
	//function that opens up GPA calculator
	const double A = 4.0;
	const double BPLUS = 3.5;
	const double B = 3.0;
	const double CPLUS = 2.5;
	const double C = 2.0;
	const double DPLUS = 1.5;
	const double D = 1.00;
	const double F = 0.0;
 
	char grade[25];
	double credithours;
	double temp = 0;
	double total = 0;
	double totalcredit = 0;
	double gpa = 0;
	int option;
	
	system("cls");
	
	printf("1. Calculate approximate GPA\n");
	printf("2. Go back\n");
	int nextmenu;
	scanf("%d", &nextmenu);
	
	int numcourses;
	
	switch(nextmenu){
		case 1:
			system("cls");
			char line[] = "Kindly enter the number of courses you have taken: ";
			printyellow(line);
			
			scanf("%d", &numcourses);
			
			for(int i = 1; i <= numcourses; i++){
				
				printf("Enter the expected grade you are going to get for course %d: ", i);
				scanf("%s", &grade);
		
				printf("Enter the credit hours of the course: ");
				scanf("%d", &credithours);
 
 
				if ((!(strcmp(grade,"A"))) || (!(strcmp(grade,"a"))))
				{
					temp = credithours * A;
				}
				else if ((!(strcmp(grade,"B+"))) || (!(strcmp(grade,"b+"))))
				{
					temp = credithours * BPLUS;
				}
				else if ((!(strcmp(grade,"B"))) || (!(strcmp(grade,"b"))))
				{
					temp = credithours * B;
				}
				else if ((!(strcmp(grade,"C+"))) || (!(strcmp(grade,"c+"))))
				{                      
					temp = credithours * CPLUS;
				}
				else if ((!(strcmp(grade,"C"))) || (!(strcmp(grade,"c"))))
				{                      
				temp = credithours * C;
				}
				else if ((!(strcmp(grade,"D+"))) || (!(strcmp(grade,"d+"))))
				{
					temp = credithours * DPLUS;
				}
				else if ((!(strcmp(grade,"D"))) || (!(strcmp(grade,"d"))))
				{                         
					temp = credithours * D;
				}
				else if ((!(strcmp(grade,"F"))) || (!(strcmp(grade,"f"))))
				{
					temp = credithours * F;
				}
				else
				{
					printf("Invaild input, please enter a valid input\n");
					i--;
					continue;
				}
 
				totalcredit = totalcredit + credithours;
				total = total + temp;
 
			}
			
			gpa = total / totalcredit;
			
			char outputline[] = "Your expected GPA is: ";
			
			printHighRed(outputline);
			printf("%f", gpa);
			getchar();
			getchar();
			GPA();
			return 0;
			break;
			
		case 2:
			othertools();
			return 0;
			break;
	}
	return 0;
}



int qgenerator(){
	//function that opens up quote generator 
	system("cls");
	
	printf("1. Generate a motivational quote\n");
	printf("2. Go back\n");
	int nextmenu;
	scanf("%d", &nextmenu);
	
	switch(nextmenu){
		
		case 1:
			srand(time(NULL));
    		int quoteseed;
    		char *quotedictionary[] = { 
				"We cannot solve problems with the kind of thinking we employed when we came up with them. - Albert Einstein" , 
  				"Learn as if you will live forever, live like you will die tomorrow. - Mahatma Gandhi" , 
  				"Stay away from those people who try to disparage your ambitions. Small minds will always do that, but great minds will give you a feeling that you can become great too. - Mark Twain" ,
  				"When you give joy to other people, you get more joy in return. You should give a good thought to happiness that you can give out. - Eleanor Roosevelt" ,
  				"When you change your thoughts, remember to also change your world. - Norman Vincent Peale" ,
  				"It is only when we take chances, when our lives improve. The initial and the most difficult risk that we need to take is to become honest. - Walter Anderson" ,
  				"Nature has given us all the pieces required to achieve exceptional wellness and health, but has left it to us to put these pieces together - Diane McLaren" ,
				"Success is not final; failure is not fatal: It is the courage to continue that counts  - Winston S. Churchill" ,
				"It is better to fail in originality than to succeed in imitation  - Herman Melville" ,
				"The road to success and the road to failure are almost exactly the same  - Colin R. Davis" ,
  				"Success usually comes to those who are too busy looking for it  - Henry David Thoreau" ,
  				"Develop success from failures. Discouragement and failure are two of the surest stepping stones to success  - Dale Carnegie" ,
				"Nothing in the world can take the place of Persistence. Talent will not; nothing is more common than unsuccessful men with talent. Genius will not; unrewarded genius is almost a proverb. Education will not; the world is full of educated derelicts. The slogan 'Press On' has solved and always will solve the problems of the human race  - Calvin Coolidge" ,
  				"There are three ways to ultimate success: The first way is to be kind. The second way is to be kind. The third way is to be kind  - Mister Rogers" ,
  				"Success is peace of mind, which is a direct result of self-satisfaction in knowing you made the effort to become the best of which you are capable  - John Wooden" ,
    			"I never dreamed about success. I worked for it  - Estée Lauder" ,
 				"Success is getting what you want, happiness is wanting what you get  - W. P. Kinsella" ,
 				"The pessimist sees difficulty in every opportunity. The optimist sees opportunity in every difficulty  - Winston Churchill" ,
  				"Don't let yesterday take up too much of today  - Will Rogers" ,
  				"You learn more from failure than from success. Don't let it stop you. Failure builds character  - Unknown " ,
 				"If you are working on something that you really care about, you don't have to be pushed. The vision pulls you  - Steve Jobs" ,
  				"Experience is a hard teacher because she gives the test first, the lesson afterwards  - Vernon Sanders Law" ,
  				"To know how much there is to know is the beginning of learning to live  - Dorothy West" ,
  				"Goal setting is the secret to a compelling future  - Tony Robbins" ,
  				"Concentrate all your thoughts upon the work in hand. The sun's rays do not burn until brought to a focus. - Alexander Graham Bell" ,
  				"Either you run the day or the day runs you  - Jim Rohn" ,
  				"I'm a greater believer in luck, and I find the harder I work the more I have of it  - Thomas Jefferson" ,
  				"When we strive to become better than we are, everything around us becomes better too  - Paulo Coelho" ,
  				"Opportunity is missed by most people because it is dressed in overalls and looks like work  - Thomas Edison" ,
  				"Setting goals is the first step in turning the invisible into the visible  - Tony Robbins" ,
  				"Your work is going to fill a large part of your life, and the only way to be truly satisfied is to do what you believe is great work. And the only way to do great work is to love what you do. If you haven't found it yet, keep looking. Don't settle. As with all matters of the heart, you'll know when you find it  - Steve Jobs" ,
  				"It's not about better time management. It's about better life management - Alexandra of The Productivity Zone" ,
				"Women challenge the status quo because we are never it  - Cindy Gallop" ,
				"We don't just sit around and wait for other people. We just make, and we do  - Arlan Hamilton" ,
  				"Think like a queen. A queen is not afraid to fail. Failure is another stepping stone to greatness  - Oprah Winfrey" ,
  				"The strongest actions for a woman is to love herself, be herself and shine amongst those who never believed she could  - Unknown" ,
  				"Whenever you see a successful woman, look out for three men who are going out of their way to try to block her  - Yulia Tymoshenko" ,
  				"Some women choose to follow men, and some choose to follow their dreams. If you're wondering which way to go, remember that your career will never wake up and tell you that it doesn't love you anymore  - Lady Gaga" ,
  				"The thing women have yet to learn is nobody gives you power. You just take it. - Roseanne Barr" ,
  				"No woman wants to be in submission to a man who isn't in submission to God! - T D Jakes" ,
  				"A witty woman is a treasure; a witty beauty is a power  - George Meredith" ,
  				"When a woman becomes her own best friend life is easier  - Diane Von Furstenberg" ,
   				"If you want something said, ask a man; if you want something done, ask a woman  - Margaret Thatcher" ,
  				"We need women at all levels, including the top, to change the dynamic, reshape the conversation, to make sure women's voices are heard and heeded, not overlooked and ignored  - Sheryl Sandberg" ,
  				"It took me quite a long time to develop a voice, and now that I have it, I am not going to be silent  - Madeleine Albright" ,
  				"Women must learn to play the game as men do  - Eleanor Roosevelt" ,
  				"I swear, by my life and my love of it, that I will never live for the sake of another man, nor ask another man to live for mine  - Ayn Rand" ,
  				"He who conquers himself is the mightiest warrior  - Confucius " ,
  				"Try not to become a man of success, but rather become a man of value  - Albert Einstein" ,
  				"One man with courage makes a majority  - Andrew Jackson" ,
  				"One secret of success in life is for a man to be ready for his opportunity when it comes  - Benjamin Disraeli" ,
  				"A man who has committed a mistake and doesn't correct it is committing another mistake  - Confucius Kongzi" ,
  				"The successful man will profit from his mistakes and try again in a different way  - Dale Carnegie" ,
  				"A successful man is one who can lay a firm foundation with the bricks others have thrown at him  - David Brinkley" ,
  				"He is a wise man who does not grieve for the things which he has not, but rejoices for those which he has  - Epictetus" ,
  				"You've got to get up every morning with determination if you're going to go to bed with satisfaction  - George Lorimer" ,
  				"Education is the most powerful weapon which you can use to change the world  - Nelson Mandela" ,
  				"The most difficult thing is the decision to act, the rest is merely tenacity  - Amelia Earhart" ,
  				"You'll find that education is just about the only thing lying around loose in this world, and it's about the only thing a fellow can have as much of as he's willing to haul away  - John Graham" ,
  				"Take the attitude of a student, never be too big to ask questions, never know too much to learn something new  - Augustine Og Mandino" ,
  				"The elevator to success is out of order. You'll have to use the stairs, one step at a time  - Joe Girard" ,
  				"Be a positive energy trampoline - absorb what you need and rebound more back  - Dave Carolan" ,
  				"People often say that motivation doesn't last. Well, neither does bathing -  that's why we recommend it daily  - Zig Ziglar" ,
  				"Work until your bank account looks like a phone number  - Unknown " ,
  				"I am so clever that sometimes I don't understand a single word of what I am saying  - Oscar Wilde" ,
  				"People say nothing is impossible, but I do nothing every day  - Winnie the Pooh" ,
  				"Life is like a sewer… what you get out of it depends on what you put into it  - Tom Lehrer" ,
  				"I always wanted to be somebody, but now I realise I should have been more specific  - Lily Tomlin" ,
  				"Talent wins games, but teamwork and intelligence win championships  - Michael Jordan" ,
  				"Individual commitment to a group effort- that is what makes a team work, a company work, a society work, a civilisation work  - Vince Lombardi" ,
  				"Teamwork is the ability to work together toward a common vision. The ability to direct individual accomplishments toward organizational objectives. It is the fuel that allows common people to attain uncommon results  - Andrew Carnegie" ,
  				"Coming together is a beginning. Keeping together is progress. Working together is success  - Henry Ford" ,
  				"Alone we can do so little, together we can do so much  - Helen Keller" ,
  				"Remember, teamwork begins by building trust. And the only way to do that is to overcome our need for invulnerability  - Patrick Lencioni" ,
  				"I invite everyone to choose forgiveness rather than division, teamwork over personal ambition  - Jean-Francois Cope" ,
  				"Just one small positive thought in the morning can change your whole day  - Dalai Lama" ,
  				"Opportunities don't happen, you create them  - Chris Grosser" ,
  				"Love your family, work super hard, live your passion  - Gary Vaynerchuk" ,
  				"It is never too late to be what you might have been  - George Eliot" ,
  				"Don't let someone else's opinion of you become your reality - Les Brown" ,
  				"If you're not positive energy, you're negative energy  - Mark Cuban" ,
  				"I am not a product of my circumstances. I am a product of my decisions  - Stephen R. Covey" ,
  				"The greatest discovery of my generation is that a human being can alter his life by altering his attitudes  - William James" ,
  				"One of the differences between some successful and unsuccessful people is that one group is full of doers, while the other is full of wishers  - Edmond Mbiaka" ,
  				"I'd rather regret the things I've done than regret the things I haven't done  - Lucille Ball" ,
				"You cannot plow a field by turning it over in your mind. To begin, begin  - Gordon B. Hinckley" ,
  				"When you arise in the morning think of what a privilege it is to be alive, to think, to enjoy, to love… - Marcus Aurelius" ,
  				"Mondays are the start of the work week which offer new beginnings 52 times a year!   - David Dweck" ,
  				"Be miserable. Or motivate yourself. Whatever has to be done, it's always your choice  - Wayne Dyer" ,
  				"Your Monday morning thoughts set the tone for your whole week. See yourself getting stronger, and living a fulfilling, happier & healthier life  - Germany Kent" ,
  				"Friday sees more smiles than any other day of the workweek! - Kate Summers" ,
  				"Oh! It's Friday again. Share the love that was missing during the week. In a worthy moment of peace and bliss  - S. O'Sade" ,
  				"Every Friday, I like to high five myself for getting through another week on little more than caffeine, willpower, and inappropriate humor  - Nanea Hoffman" ,
 	 			"Make a Friday a day to celebrate work well done that you can be proud of knowing that you just didn't put in time to the next paycheck  - Byron Pulsifer" ,
  				"When you leave work on Friday, leave work. Don't let technology follow you throughout your weekend (answering text messages and emails) take a break you will be more refreshed to begin the workweek if you have had a break  - Catherine Pulsifer" ,
  				"You can get everything in life you want if you will just help enough other people get what they want  - Zig Ziglar" ,
  				"Inspiration does exist, but it must find you working  - Pablo Picasso" ,
	  			"Don't settle for average. Bring your best to the moment. Then, whether it fails or succeeds, at least you know you gave all you had  - Angela Bassett" ,
  				"Show up, show up, show up, and after a while the muse shows up, too  - Isabel Allende" ,
  				"Don't bunt. Aim out of the ballpark. Aim for the company of immortals  - David Ogilvy" ,
  				"I have stood on a mountain of no's for one yes  - Barbara Elaine Smith" ,
	  			"If you believe something needs to exist, if it's something you want to use yourself, don't let anyone ever stop you from doing it  - Tobias Lutke" ,
  				"Don't look at your feet to see if you are doing it right. Just dance  - Anne Lamott" ,
  				"Someone's sitting in the shade today because someone planted a tree a long time ago  - Warren Buffet" ,
  				"True freedom is impossible without a mind made free by discipline  - Mortimer J. Adler" ,
  				"Rivers know this: there is no hurry. We shall get there some day  - A.A. Milne" ,
  				"There is a vitality, a life force, an energy, a quickening that is translated through you into action, and because there is only one of you in all time, this expression is unique. And if you block it, it will never exist through any other medium and will be lost  - Martha Graham" ,
  				"Small is not just a stepping-stone. Small is a great destination itself  - Jason Fried" ,
  				"He that can have patience can have what he will  - Benjamin Franklin" ,
  				"The only one who can tell you   \"you can't win\" is you and you don't have to listen  - Jessica Ennis" ,
  				"Set your goals high, and don't stop till you get there  - Bo Jackson" ,
  				"Take your victories, whatever they may be, cherish them, use them, but don't settle for them  - Mia Hamm" ,
  				"Life can be much broader once you discover one simple fact: Everything around you that you call life was made up by people that were no smarter than you. And you can change it, you can influence it… Once you learn that, you'll never be the same again  - Steve Jobs" ,
  				"Life is like riding a bicycle. To keep your balance you must keep moving  - Albert Einstein" ,
  				"What you do speaks so loudly that I cannot hear what you say  - Ralph Waldo Emerson" ,
  				"I have never let my schooling interfere with my education  - Mark Twain" ,
  				"If you can't yet do great things, do small things in a great way  - Napoleon Hill" ,
  				"If you really want to do something, you'll find a way. If you don't, you'll find an excuse  - Jim Rohn" ,
  				"Be sure you put your feet in the right place, then stand firm  - Abraham Lincoln" ,
  				"Live out of your imagination, not your history  - Stephen Covey" ,
  				"Do not wait for the perfect time and place to enter, for you are already onstage  - Unknown" ,
  				"The greater the difficulty, the more the glory in surmounting it  - Epicurus" ,
				"Courage doesn't always roar. Sometimes courage is a quiet voice at the end of the day saying, \"I will try again tomorrow\"  - Mary Anne Radmacher" ,
  				"If the decisions you make about where you invest your blood, sweat, and tears are not consistent with the person you aspire to be, you'll never become that person  - Clayton M. Christensen" ,
  				"Fear of what other people will think is the single most paralyzing dynamic in business and in life. The best moment of my life was the day I realized that I no longer give a damn what anybody thinks. That's enormously liberating and freeing, and it's the only way to live your life and do your business - Cindy Gallop" ,
  				"The only way of discovering the limits of the possible is to venture a little way past them into the impossible  - Arthur C. Clarke" ,
				"Worry is a misuse of imagination  - Unknown " ,
  				"Courage is the most important of all the virtues because without courage, you can't practice any other virtue consistently  - Maya Angelou" ,
				"I never look back, darling. It distracts from the now  - Edna Mode" ,
				"A year from now you will wish you had started today  - Unknown" ,
				"The reason we struggle with insecurity is because we compare our behind-the-scenes with everyone else's highlight reel  - Steve Furtick" ,
				"Somewhere, something incredible is waiting to be known  - Carl Sagan" ,
  				"I will not lose, for even in defeat, there's a valuable lesson learned, so it evens up for me  - Jay-Z" ,
  				"I do not try to dance better than anyone else. I only try to dance better than myself  - Arianna Huffington" ,
  				"If you don't risk anything, you risk even more  - Erica Jong" ,
  				"Failure is simply the opportunity to begin again, this time more intelligently  - Henry Ford" ,
  				"Our greatest glory is not in never falling, but in rising every time we fall  - Confucius " ,
  				"If you change the way you look at things, the things you look at change  - Wayne Dyer" ,
  				"We must reach out our hand in friendship and dignity both to those who would befriend us and those who would be our enemy  - Arthur Ashe" ,
  				"It's fine to celebrate success but it is more important to heed the lessons of failure  - Bill Gates" ,
  				"I can't tell you how many times I've been given a no. Only to find that a better, brighter, bigger yes was right around the corner  - Arlan Hamilton" ,
  				"We need to accept that we won't always make the right decisions, that we'll screw up royally sometimes - understanding that failure is not the opposite of success, it's part of success  - Ariana Huffington" ,
  				"When everything seems to be going against you, remember that the airplane takes off against the wind, not with it  - Henry Ford" ,
  				"You cannot always control what goes on outside. But you can always control what goes on inside  - Wayne Dyer" ,
  				"We are what we repeatedly do. Excellence, then, is not an act, but a habit  - Aristotle" ,
  				"Start where you are. Use what you have. Do what you can  - Arthur Ashe" ,
  				"Hustle beats talent when talent doesn't hustle - Ross Simmonds" ,
  				"Everything you've ever wanted is sitting on the other side of fear  - George Addair" ,
  				"The question isn't who is going to let me; it's who is going to stop me  - Ayn Rand" ,
  				"Every strike brings me closer to the next home run  - Babe Ruth" ,
  				"I have not failed. I've just found 10,000 ways that won't work  - Thomas A. Edison" ,
  				"Don't worry about failure; you only have to be right once  - Drew Houston" , 
  				"You carry the passport to your own happiness  - Diane von Furstenberg" ,
  				"Never let success get to your head and never let failure get to your heart  - Drake" ,
  				"Ideation without execution is delusion  - Robin Sharma" ,
  				"Make sure your worst enemy doesn't live between your own two ears  - Laird Hamilton" ,
  				"It is a rough road that leads to the heights of greatness  - Lucius Annaeus Seneca" ,
  				"For the great doesn't happen through impulse alone, and is a succession of little things that are brought together  - Vincent van Gogh" ,
  				"If we take care of the moments, the years will take care of themselves  - Maria Edgeworth" ,
  				"Resilience is when you address uncertainty with flexibility  - Unknown" ,
  				"Sometimes magic is just someone spending more time on something than anyone else might reasonably expect  - Raymond Joseph Teller" ,
  				"It's not the will to win that matters- everyone has that. It's the will to prepare to win that matters  - Paul Bryant" ,
  				"As a single footstep will not make a path on the earth, so a single thought will not make a pathway in the mind. To make a deep physical path, we walk again and again. To make a deep mental path, we must think over and over the kind of thoughts we wish to dominate our lives  - Henry David Thoreau" ,
  				"Never give up on a dream just because of the time it will take to accomplish it. The time will pass anyway  - Earl Nightingale" ,
  				"True humility is not thinking less of yourself; it is thinking of yourself less  - C.S. Lewis" ,
  				"The two most important days in your life are the day you're born and the day you find out why  - Mark Twain" ,
  				"Nothing ever goes away until it teaches us what we need to know  - Pema Chodron" ,
  				"We can see through others only when we can see through ourselves  - Bruce Lee" ,
  				"First forget inspiration. Habit is more dependable. Habit will sustain you whether you're inspired or not. Habit will help you finish and polish your stories. Inspiration won't. Habit is persistence in practice  - Octavia Butler" ,
  				"The best way out is always through  - Robert Frost" ,
  				"The battles that count aren't the ones for gold medals. The struggles within yourself- the invisible, inevitable battles inside all of us- that's where it's at  - Jesse Owens" ,
  				"If there is no struggle, there is no progress  - Frederick Douglass" ,
  				"Someone will declare,   \"I am the leader!\" and expect everyone to get in line and follow him or her to the gates of heaven or hell. My experience is that it doesn't happen that way. Others follow you based on the quality of your actions rather than the magnitude of your declarations  - Bill Walsh" ,
  				"Courage is like a muscle. We strengthen it by use  - Ruth Gordo" ,
  				"More is lost by indecision than wrong decision  - Marcus Tullius Cicero" ,
  				"If the highest aim of a captain were to preserve his ship, he would keep it in port forever  - Thomas Aquinas" ,
  				"You can be the ripest, juiciest peach in the world, and there's still going to be somebody who hates peaches  - Dita Von Teese" ,
  				"Keep a little fire burning; however small, however hidden  - Cormac McCarthy" ,
  				"You\'ll never get bored when you try something new. There's really no limit to what you can do  - Dr. Seuss" , 
  				"I think it's intoxicating when somebody is so unapologetically who they are  - Don Cheadle" ,
 	 			"You can never leave footprints that last if you are always walking on tiptoe  - Leymah Gbowee" ,
  				"If you don't like the road you're walking, start paving another one  - Dolly Parton" ,
  				"If it makes you nervous, you're doing it right  - Childish Gambino" ,
  				"What you do makes a difference, and you have to decide what kind of difference you want to make  - Jane Goodall" ,
  				"I choose to make the rest of my life the best of my life  - Louise Hay" ,
  				"In order to be irreplaceable one must always be different  - Coco Chanel" ,
  				"Anything can make me stop and look and wonder, and sometimes learn  - Kurt Vonnegut" ,
  				"People's passion and desire for authenticity is strong  - Constance Wu" ,
  				"A surplus of effort could overcome a deficit of confidence  - Sonia Sotomayor" ,
  				"Doubt is a killer. You just have to know who you are and what you stand for  - Jennifer Lopez" ,
  				"No one changes the world who isn't obsessed  - Billie Jean King" ,
  				"I learned a long time ago that there is something worse than missing the goal, and that's not pulling the trigger  - Mia Hamm" ,
  				"Some people want it to happen, some wish it would happen, others make it happen  - Michael Jordan" ,
  				"It is remarkable how much long-term advantage people like us have gotten by trying to be consistently not stupid, instead of trying to be very intelligent  - Charlie Munger" ,
  				"You can't be that kid standing at the top of the waterslide, overthinking it. You have to go down the chute  - Tina Fey" ,
  				"When I believe in something, I'm like a dog with a bone  - Melissa McCarthy" ,
  				"And the day came when the risk to remain tight in a bud was more painful than the risk it took to blossom  - Anaïs Nin" ,
  				"The standard you walk past, is the standard you accept  - David Hurley" ,
  				"I've searched all the parks in all the cities and found no statues of committees  - Gilbert K. Chesterton" ,
  				"Success is stumbling from failure to failure with no loss of enthusiasm  - Winston Churchill" ,
  				"Keep your eyes on the stars, and your feet on the ground  - Theodore Roosevelt" ,
  				"Do not stop thinking of life as an adventure. You have no security unless you can live bravely, excitingly, imaginatively; unless you can choose a challenge instead of competence  - Eleanor Roosevelt" ,
  				"Perfection is not attainable. But if we chase perfection we can catch excellence  - Vince Lombardi" ,
  				"Get a good idea and stay with it. Dog it, and work at it until it's done right  - Walt Disney" ,
  				"Optimism is the faith that leads to achievement. Nothing can be done without hope and confidence  - Helen Keller" 
			};
			system("cls");
    		char quote[] = "";
    		quoteseed = rand() % 205;
    		strcpy(quote,quotedictionary[quoteseed]);
    		printgreen(quote);
    		getchar();
			getchar();
    		qgenerator();
    		return 0;
    		break;

		case 2:
			othertools();
			return 0;
			break;
	}
	return 0;
}