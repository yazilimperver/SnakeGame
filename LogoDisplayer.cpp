
#include "LogoDisplayer.h"
#include <iostream>
using namespace std;

constexpr char logoText[] = R"(
             ('-.      .-') _                        _   .-')     _ (`-.   ('-. _  .-')       (`-.     ('-. _  .-')   
            ( OO ).-. (  OO) )                      ( '.( OO )_  ( (OO  )_(  OO( \( -O )    _(OO  )_ _(  OO( \( -O )  
  ,--.   ,--/ . --. ,(_)----.  ,-.-') ,--.     ,-.-'),--.   ,--._.`     (,------,------.,--(_/   ,. (,------,------.  
   \  `.'  /| \-.  \|       |  |  |OO)|  |.-') |  |OO|   `.'   (__...--''|  .---|   /`. \   \   /(__/|  .---|   /`. ' 
 .-')     .-'-'  |  '--.   /   |  |  \|  | OO )|  |  |         ||  /  | ||  |   |  /  | |\   \ /   / |  |   |  /  | | 
(OO  \   / \| |_.'  (_/   /    |  |(_/|  |`-' ||  |(_|  |'.'|  ||  |_.' (|  '--.|  |_.' | \   '   /,(|  '--.|  |_.' | 
 |   /  /\_ |  .-.  |/   /___ ,|  |_.(|  '---.,|  |_.|  |   |  ||  .___.'|  .--'|  .  '.'  \     /__)|  .--'|  .  '.' 
 `-./  /.__)|  | |  |        (_|  |   |      (_|  |  |  |   |  ||  |     |  `---|  |\  \    \   /    |  `---|  |\  \  
   `--'     `--' `--`--------' `--'   `------' `--'  `--'   `--'`--'     `------`--' '--'    `-'     `------`--' '--' 
)";

constexpr char snakeLogo[] = R"(                                                                                                                        
                                                     .-/+oosssyyyyyysoo+/-.                                            
                                                ./ohNMMMMMMMMMMMMMMMMMNmmNMNmyo/-                                      
                                              /yNMMMMMMMMMMMMMMMMMMMMMh    :NMMMMNh+-                                  
                                            -dMMMMMMMMMMMmhysosyhmMMMMMmdhsdMMMMMMMMNmo                                
                                           /NMMMMMMMMMmo-         yMMMMMMMdo:---/oNMMMy                                
                                          .NMMMMMMMMMo             mMMMMMm        /MMm                                 
                                          oMMMMMMMMMs              oMMMMMd         mM:                                 
                                          oMMMMMMMMMs              :MMMMMMy        s/                                  
                                          :MMMMMMMMMMs.             ohmMMMMm+.                                         
                                           sMMMMMMMMMMms-             .-ohmMMNmmm+                                     
                                            sMMMMMMMMMMMNmy/:.             -+ymy:                                      
                                             /dMMMMMMMMMMMMMNNmhso/::-.                                                
                                              .+dMMMMMMMMMMMMMMMMMMMNNmmdhyo/-                                         
                                                 :sdMMMMMMMMMMMMMMMMMMMMMMMMMNmy/.                                     
                                                    -+ydmMMMMMMMMMMMMMMMMMMMMMMMMmy-                                   
                                                        --:+syhdmNMMMMMMMMMMMMMMMMMNy.                                 
                                  :+osss+:.                     ..-/shmMMMMMMMMMMMMMMm/                                
                               -smNMMMMMMMmy/                         .:smMMMMMMMMMMMMN/                               
                              +mMMMMMMMMMMMMMms.                         ./dMMMMMMMMMMMN-                              
                             /MMMMMMMho+oymNMMMNy:                         .sMMMMMMMMMMMs                              
                             NMMMMMMs      :smMMMMh/.                        yMMMMMMMMMMm                              
                            .MMMMMMM/        .+dNMMMms:.                     .MMMMMMMMMMN                              
                             NMMMMMMd.          :smMMMMmyo/-.. .--.           NMMMMMMMMMd                              
                             oMMMMMMMh.           ./sdNNMMMMNmdhs/.          /MMMMMMMMMMo                              
                              yMMMMMMMNo.             .:/+o+/:-             -mMMMMMMMMMm                               
                               oNMMMMMMMNs:.                               /mMMMMMMMMMN-                               
                                -hMMMMMMMMMds:.                         .:hMMMMMMMMMMm:                                
                                  :hNMMMMMMMMMNdy+:..                ./smMMMMMMMMMMMh-                                 
                                    -omMMMMMMMMMMMMMNmdhyyyssoossyydmMMMMMMMMMMMMMm+                                   
                                       :ohNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMd/                                     
                                          .:oymMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNdo-                                       
                                                :+shdNMMMMMMMMMMMMMMMMMNmyo:.                                          
                                                       .-:/+++ooo++/:-.                                                
                                                                                                                       
		                       ~~~~~ WELCOME TO BEGUM THE SNAKE TAMER GAME ~~~~~
)";

void LogoDisplayer::DisplaySnakeLogo()
{
	std::cout << snakeLogo << endl;
	return;

}

void LogoDisplayer::DisplayYazilimPerverLogoText1()
{
	std::cout << logoText << endl;
   	return;	
}
