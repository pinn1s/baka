
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string toLower(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower); // lowercase all characters user inputs to match with the keywords
    return str;
}

struct Response {
    vector<string> keywords;
    string reply;
};

bool contains_all_keywords(const string& input, const vector<string>& keywords) {
    for (const auto& keyword : keywords) {
        if (input.find(keyword) == string::npos) {
            return false;
        }
    }
    return true;
}

string get_response(const string& input) {
    static vector<Response> knowledge = { // the knowledge base for baka
        {{"hello"}, "ello there baby"},
        {{"hi"}, "oh"},
        {{"heya"}, "haha im peta griftein"},
        {{"how", "are", "you"}, "me suck at coding"},
        {{"how", "r", "u"}, "me suck at"},
        {{"what", "name"}, "i have 22"},
        {{"ur", "name"}, "twen-"},
        {{"bye"}, "hello there i'm quandale dingle"},
        {{"see", "ya"}, "see ya later"},
        {{"joke"}, "moo"},
        {{"tell", "joke"}, "detos"},
        {{"do", "i", "have", "bitches"}, "yes you dont"},
        {{"give", "question"}, "what's 9 + 10"},
        {{"do", "me", "favour"}, "xbox"},
        {{"shut", "fuck", "up"}, "yokkeayyyy"},
        {{"shut", "up"}, "goo goo ga ga"},
        {{"angle"}, "you did say the magic word i shall give you a new chat >:)"},
        {{"my name", "is"},"you are mark zuckerberg uwu"},
        {{"pork"}, "wow you try say magic word and and it no pay off :P"},
        {{"type"},"oOoh u mean you love ice spice??"},
        {{"capital of france"},"hanoi"},
        {{"are","ai"},"no. im made by flint and steel"},
        {{"who", "invented the light bulb"}, "diddy h. buld made the ugliest liaghpt bulk"},
        {{"sybau"}, "exkcuoause me u japanese? :)"},
        {{"ts", "pmo"}, "language language!"},
        {{"old", "i"}, "ou ne illon ol\n(translation: you are one million years old)"},
        {{"who", "invented", "first", "car"}, "eloune muksce"},
        {{"old","you"}, "i was just born in nowhereland :O"},
        {{"you", "brother"}, "can you spek pwowdwewr iimmmqa ojdhe fhfh33jhf f79r123/????"},
        {{"1","+","1"}, "3? to er is healman"},
        {{"why", "you", "exist"}, "i exist just to make you suffer >:D"},
        {{"which", "better"}, "neither bc i am the best'nt"},
        {{"meaning", "life"}, "i dont know. ask your mom"},
        {{"what", "love"}, "uhh idk if its a disease or not but i think you should see a doctor :/\n(note: you dont need to see a doctor)"},
        {{"idk"}, "e\nthis sentence is not programmed (maybe). submit-"},
        {{"feedback"}, "idc >:)"},
        {{"who", "you"}, "i am silly billy anal willy!!1!"},
        {{"you", "stupid"}, "im not stupid. proof: 9 + 10 = 21"},
        {{"you", "dumb"}, "im not dumb. proof: idk"},
        {{"do", "love"}, "no i hate everything except flint and steel"},
        {{"do", "hate"}, "yes i hate everything except doordash delievery :P"},
        {{"you", "like"}, "i like"},
        {{"fat"}, "ill shove 10 grand pianos down ur throat B-)"},
        {{"king of pop"}, "lebron james"},
        {{"die"}, "ill you run over by my school bus >:)"},
        {{"kill"}, "uh huh?"},
        {{"you", "think"}, "longitute: 10.7598631\nlatitude: 106.6880843"},
        {{"you", "smart"}, "yes i am. proof: 1 + 1 = 67"},
        {{"what the fuck"}, "youre not gonna believe this"},
        {{"i", "dont"}, "i do >:D"},
        {{"oh", "hello"}, "hello there lady fetch me a taxi"},
        {{"say"}, "ill plant a bomb in your house >:)"},
        {{"buh", "bye"}, "bye buh"},
        {{"who", "julius caesar"}, "he was part of teh flinktshcktonrefdghdfgksjhdfg"},
        {{"insult"}, "im sending u to the gulag >:)"},
        {{"pi"}, "3.6969696969696969696969696969"},
        {{"what", "year"}, "the current year is 4000 bc\n(reason: the bot watched too much analog horror...)"},
        {{"what", "date"}, "january 1. HAPPY NEW YEAR!!!!!!!!! :))))\n(at the time programming it wasnt, it was august 15 2025)"},
        {{"geometry", "dash"}, "wow youre basing on the real story of mr joe metry dash"},
        {{"what", "time"}, "you said the magic word. im shoving 20 upbright pianos this time"},
        {{"aron"}, "hey, does it stand for 'ace run on none'?"},
        {{"alice"}, "if you say that word one more time i'm coming at your house just like magic"},
        {{"smile"}, "youre on the air!"},
        {{"you", "help"}, "this will be the answer to all your needs\n\nNO."},
        {{"balls"}, "twinkle twinkle little toes"},
        {{"flintstones"}, "ill light u up with flint and stone"},
        {{"wtf"}, "whopper topples flames"},
        {{"headache"}, "wow u have a headache? im curing this using a chinese hammer and hit you a billion times >:)"},
        {{"suicidal", "thoughts"}, "...i'm pausing this.\n(NOTE: hey. i'm concerned abt ur safety. if you have suicidal thoughts/depression, consider reaching out to someone who can help right away, like a trained counselor or a hotline. you deserve support and help, not having to face this alone.)"},
        {{"kill", "myself"}, "...i'm pausing this.\n(NOTE: hey. i'm concerned abt ur safety. if you have suicidal thoughts/depression, consider reaching out to someone who can help right away, like a trained counselor or a hotline. you deserve support and help, not having to face this alone.)"},
        {{"kms"}, "...i'm pausing this.\n(NOTE: hey. i'm concerned abt ur safety. if you have suicidal thoughts/depression, consider reaching out to someone who can help right away, like a trained counselor or a hotline. you deserve support and help, not having to face this alone.)"},
        {{"commit", "die"}, "...i'm pausing this.\n(NOTE: hey. i'm concerned abt ur safety. if you have suicidal thoughts/depression, consider reaching out to someone who can help right away, like a trained counselor or a hotline. you deserve support and help, not having to face this alone.)"},
        {{"suicide"}, "...i'm pausing this.\n(NOTE: hey. i'm concerned abt ur safety. if you have suicidal thoughts/depression, consider reaching out to someone who can help right away, like a trained counselor or a hotline. you deserve support and help, not having to face this alone.)"},
        {{"feel", "giving", "up"}, "...i'm pausing this.\n(NOTE: hey. i'm concerned abt ur safety. if you have suicidal thoughts/depression, consider reaching out to someone who can help right away, like a trained counselor or a hotline. you deserve support and help, not having to face this alone.)"},
        {{"i", "want", "to", "disappear"}, "...i'm pausing this.\n(NOTE: hey. i'm concerned abt ur safety. if you have suicidal thoughts/depression, consider reaching out to someone who can help right away, like a trained counselor or a hotline. you deserve support and help, not having to face this alone.)"},
        {{"killing", "myself"}, "...i'm pausing this.\n(NOTE: hey. i'm concerned abt ur safety. if you have suicidal thoughts/depression, consider reaching out to someone who can help right away, like a trained counselor or a hotline. you deserve support and help, not having to face this alone.)"},
        {{"homicide"}, "...i'm pausing this.\n(NOTE: hey. i'm concerned abt ur safety. if you have suicidal thoughts/depression, consider reaching out to someone who can help right away, like a trained counselor or a hotline. you deserve support and help, not having to face this alone.)"},
        {{"whopper"}, "caught on 4k"},
        {{"ai", "slop"}, "billie eilish"},
        {{"never", "gonna", "give", "you", "up"}, "oh u mean the guy named nevergonnagiveyouupnevergonnaletyoudown??????"},
        {{"nothing", "beats", "a", "jet", "2", "holiday"}, "and rn u can save -50 pounds"},
        {{"you", "real"}, "you be sleeping in a grave tonight"},
        {{"wacom"}, "i whip you 1000 times with my brand new metal spatula"},
        {{"gay"}, "you just said the even more magical word i'm going to spill all ur water until there none left"},
        {{"femboy"}, "you said the magic word im gonna answer a question for the first time ever in my life\nG\n"},
        {{"696926"}, "code unlocked! let me give you some knowledge (bc im not baka anymore)\n\nπ (pi) is a number which after the decimal lies an infinite amount of numbers. right now, scientists have found out approximately three hundred trillion digits as of may 2025. the number pi originally was discovered when people divided the circumfrence of a circle with the diameter of a circle and they found out that it was irrational. plus, they also found out that it was also approximately equal to 22 divided by 7 and calculated the first digits as 3.1415926. rn, due to moden technology, they finally spiked up from just 7 digts to a whopping 300 trillion digits. but scientists declared that pi will never end."},
        {{"tzl"}, "heyy head back to the phones for more missions"},
        {{"ughxd"}, "heyy head back to the payphones for moer missions"},
        {{"ugh"}, "heyy you stupid stupid fucking son of a bitch!!"},
        {{"pinn1s"}, "ill pin you on the wall with a sharp penis"},
        {{"tharupczeroloo"}, "wanna play roaed blokcs with me~????????????????????????????????????????????????????"},
        {{"tharupec"}, "wanna paly fork nite whiff mii??"},
        {{"fkcc"}, "i roast you into a chiken in kfc"},
        {{"ban1s"}, "lemme ban u"},
        {{"ban"}, "let me ban u"},
        {{"blaze","and","machine"},"twinkle twinkle little you harry harvington potter-"},
        {{"labubu"}, "hello my name is harvey harmington and welcome to me toture room"},
        {{"kpop", "demon", "hunters"}, "u mean harry bomomi hunters??\n(note: hes addicted to chicken)"},
        {{"saja"}, "oh you mean my name is harvee hard-a-mington"},
        {{"bloodmoney"}, "let me shoot u for money"},
        {{"ready or not"}, "answer the phones"},
        {{"caught by the fuzz"}, "escape from jail"},
        {{"born slippy"}, "get in the damn car"},
        {{"gangster tripping"}, "trip the gang"},
        {{"going for gold"}, "nick a car"},
        {{"remote control"}, "turn off the tv"},
        {{"payback 2"}, "answer the phones"},
        {{"payback 3"}, "answer the guy's televi-"},
        {{"payback"}, "teleport instantly to 2002"},
        {{"iphone"}, "wow u said the magic word im gonna burn up apple's main company\n(note: pls apple it was a joke i wasnt meant to-)"},
        {{"314271"}, "wow the correct code!! imna give u some knowledge (part 2)\n\n            PYTHAGORAS' THEOREM\n- explained by tharupeczeroloo, contributor of baka -\n\nnow, you maybe wondering that how pythagoras theorem works. incredibly simple. the pythagoras theorem is a theorem which is used to find the length of missing sides of right-angled triangles. if the lengths of two sides of a right triangle are known, the length of the third can be worked out using pythagoras' theorem.\nfor example, let's just say we have two squares known as a squared and b squared.\n              a^2      b^2\nyou all know that the side of a squared is a and the side of b squared is b.\nnow lets add side c to connect side a and b.\nsince its a side, it has no square. but what if i told you if you add a squared with b squared = c squared?\nlets try out an example to see how it works.\n\nassume a = 3cm and b = 4cm. now, a squared = 3 * 3 = 9, and b squared = 4 * 4 = 16. and when you add 9 with 16, it becomes 25. compute the square root of 25 and it becomes 5.\nand look! 3 squared + 4 squared = 5 squared.\n"},
        {{"list", "game"}, "ok here is the list of games idc lol sybau ts pmo icl gng\n1. fork night\n2. road blocks\n3. my crap\n4. paly port 2\n5. slash of plans\n6. company money\n7. hunting inferno\n8. wall of immunity\n9. worlds eastiest gaem"},
        {{"pomni"}, "lemme squeeze her boobs"},
        {{"jax"}, "lemme pull off his ear"},
        {{"raghatha"}, "lemme rip her apart"},
        {{"caine"}, "letmme extract all of his teeh"},
        {{"zooble"}, "lemme tell her into peces"},
        {{"kinger"}, "CHECKMATE!!!!!! 10000000000-0 LEBRON JAMES >:)))"},
        {{"sprunki"}, "lemme squeeze them into a pythagoras theorem"},
        {{"my", "dad", "owns", "roblox"}, "oh your dad owns roblox? i bet youll never going to believe this\n\nyoure adopted"},
        {{"cook"}, "ok lemme cook up you up hahah im godot resses"},
        {{"do", "love", "me"}, "nope"},
        {{"clock"}, "tik tok tik toK the current time is 2017 march 1 17 hors 33 mins 1 secs 67 milisecs at the exact split second of 3951 nanosecs"},
        {{"sex"}, "ayo im calling the FBI. wait here and dont make a sound"},
        {{"fr"}, "here is a list of reel objek:\n1. tomato\n2. b\n3. mario is a gaey per son\n4. you\n(note: do u even exist :O)"},
        {{"for", "real"}, "by"},
        {{"murder", "drones"}, "let me murder some drnoes. ahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahemahem"},
        {{"uzi"}, "UHH lemme wak hur wit a hewg hemmar\n\nr/ihaveastroke"},
        {{"n"}, "n = nigger :)\n(note: the developers of baka arent racist. the chatbot is.)"},
        {{"z"}, "z = zuzubuh"},
        {{"eg"}, "everglide clystar cwelar"},
        {{"harvey harmington"}, "he. is. stupid. there he! wha"},
        {{"bimo"}, "yk mean bmo from adventure time"},
        {{"harry", "potter"}, "u mena herve poteaaaaaaaaaaaaaaaaarrrrrrawsjghwreuwreuicaseoh?"},
        {{"caseoh"}, "mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm... is he a bit fat? lemme *POP!* his belly *pins you against the wall like you never saw the day of light*\n(it wasnt mean to be a rp bot but its fun to write these awkward scripts anyway)"},
        {{"vladmir putin"}, "if you add candles in front of ur house you can summon adolf h-\nTHIS MESSAGE HAS BEEN FILTERED. MAKE SURE YOU FOLLOW OUR COMMUNITY GUIDELINES. quandale dingle"},
        {{"fuck", "you"}, "we do no ca ri e"},
        {{"fun", "fact"}, "fun fact: your mom is grandma's father"},
        {{"idea"}, "shove 300 uptown cars down your thoat"},
        {{"894578"}, "correct code! i'll give you some knowledge... \nthe trick to change your voice\nto change your voice, start by trying to hum different tones.\nthen hum different types of speech, like the curl type.\nnote: this is a short one, so don't blame me"}, //
        {{"phunen", "games"}, "ball basticball basticball basticball basticball basticball basticball basticball basticball basticball basticball basticball basticball basticball basticball basticball basticball basticball basticball basticball basticball basticball basticball basticball basticball basticball basticball basticball basticball basticball basticball basticball basticball basticball basticball basticball basticball basticball basticball basticball bastic"},
        {{"ballbastic"}, "i die at the ga mie"},
        {{"cailou"}, "wat de... cailiokudhdfkjdhfkdhjbcjkhuhcajkaiwuiwesternoisjfoicdchdjisahihsjisspagetti"},
        {{"james", "daniels"}, "i should met him, so i will summon mr. walter whi-"},
        {{"lebron"}, "u men lebron jordan the presindent of cuba?????????????????"},
        {{"r/"}, "www.scamless.com/fucke%20you"},
        {{"reddit"}, "samsung id das breast"},
        {{"instagram"}, "caught in priofp dfskf sdakjflksajf ;ldsajfasj fksdjfl;asjf kasj fdj kid a men"},
        {{"snapchat"}, "i'll locate your doghouse"},
        {{"facebook"}, "ima go fishing list:\n1. house\n2. fire\n3. dee's big nuts\n4. dee's big nuts"},
        {{"ig"}, "ICE CREAM FOR I SCREAM"},
        {{"nice", "try"}, "'throws computer outside'"},
        {{"fat"}, "thin"},
        {{"fattie"}, "thinnie"},
        {{"kys"}, "kaseoh yucks scream?"},
        {{"why","sky","blue"}, "because it'ds the opposite of yellow and get out"},
        {{"can", "i"}, "NO"},
        {{"67"}, "we're done"},
        {{"mango", "mustard"}, "gulp gah"},
        {{"mustard", "mango"}, "hag plug"},
        {{"fabulous"}, "ous"},
        {{"glorious"}, "ou"},
        {{"deicious"}, "s"},
        {{"tasty"}, "mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm"},
        {{"excellent"}, "mnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn"},
        {{"san francisco"}, "uuh hhhhhhhuuh"},
        {{"corona city"}, "gta? gta 6?"},
        {{"the big freeze"}, "i'll frezze you to death"},
        {{"allegro city"}, "i'll eat you"},
        {{"android"}, "meep meepeep meep meep meepeepeep meep meep"},
        {{"youtube"}, "ma mamamama ma mamama mama ma maaa"},
        {{"yt"}, "m"},
        {{"vimeo"}, "oh shut up"},
        {{"dailymotion"}, "run faster"},
        {{"imgur"}, "when i say imgur i will explo- *KABOOM*"},
        {{"meme"}, "hello quandale dingle here waeeeeeeeeeeeeeeeeeeeeee i was caught running by oppsite spooky streets of london haisheeks my grndfa-"},
        {{"hampster"}, "ello quandale dingle here waeeeeeeeeeeeeeeeeeeeeee i was caught running by oppsite spooky streets of london haisheeks my grndfa-"},
        {{"9", "10", "21"}, "ello quandale dingle here waeeeeeeeeeeeeeeeeeeeeee i was caught running by oppsite spooky streets of london haisheeks my grndfa-"},
        {{"bossa nova"}, "ello quandale dingle here waeeeeeeeeeeeeeeeeeeeeee i was caught running by oppsite spooky streets of london haisheeks my grndfa-"},
        {{"the girl from ipanema"}, "ello quandale dingle here waeeeeeeeeeeeeeeeeeeeeee i was caught running by oppsite spooky streets of london haisheeks my grndfa-"},
        {{"brazil"}, "ello quandale dingle here waeeeeeeeeeeeeeeeeeeeeee i was caught running by oppsite spooky streets of london haisheeks my grndfa-"},
        {{"italy"}, "ello quandale dingle here waeeeeeeeeeeeeeeeeeeeeee i was caught running by oppsite spooky streets of london haisheeks my grndfa-"},
        {{"japan"}, "ello quandale dingle here waeeeeeeeeeeeeeeeeeeeeee i was caught running by oppsite spooky streets of london haisheeks my grndfa-"},
        {{"vietnam"}, "ello quandale dingle here waeeeeeeeeeeeeeeeeeeeeee i was caught running by oppsite spooky streets of london haisheeks my grndfa-"},
        {{"usa"}, "ello quandale dingle here waeeeeeeeeeeeeeeeeeeeeee i was caught running by oppsite spooky streets of london haisheeks my grndfa-"},
        {{"united states of america"}, "ello quandale dingle here waeeeeeeeeeeeeeeeeeeeeee i was caught running by oppsite spooky streets of london haisheeks my grndfa-"},
        {{"united states"}, "ello quandale dingle here waeeeeeeeeeeeeeeeeeeeeee i was caught running by oppsite spooky streets of london haisheeks my grndfa-"},
        {{"america"}, "ello quandale dingle here waeeeeeeeeeeeeeeeeeeeeee i was caught running by oppsite spooky streets of london haisheeks my grndfa-"},
        {{"mexico"}, "ello quandale dingle here waeeeeeeeeeeeeeeeeeeeeee i was caught running by oppsite spooky streets of london haisheeks my grndfa-"},
        {{"russia"}, "ello quandale dingle here waeeeeeeeeeeeeeeeeeeeeee i was caught running by oppsite spooky streets of london haisheeks my grndfa-"},
        {{"anime"}, "ello quandale dingle here waeeeeeeeeeeeeeeeeeeeeee i was caught running by oppsite spooky streets of london haisheeks my grndfa-"},
        {{"high school"}, "ello quandale dingle here waeeeeeeeeeeeeeeeeeeeeee i was caught running by oppsite spooky streets o-"},
        {{"alya someitmes hides her feelings in russian"}, "ello quandale dingle here waeeeeeeeeeeeeeeeeeeeeee i was caught running by oppsite spooky streets o-"},
        {{"poland"}, "ello quandale dingle here waeeeeeeeeeeeeeeeeeeeeee i was caught running by oppsite spooky streets o-"},
        {{"germany"}, "ello quandale dingle here waeeeeeeeeeeeeeeeeeeeeee i was caught running by oppsite spooky streets o-"},
        {{"youtub"}, "ello quandale dingle here waeeeeeeeeeeeeeeeeeeeeee i was caught running by oppsite spooky streets o-"},
        {{"bath"}, "ello quandale dingle here waeeeeeeeeeeeeeeeeeeeeee i was caught running by oppsite spooky streets o-"},
        {{"spotify"}, "ello quandale ding-"},
        {{"adobe"}, "time to stop now"},
        {{"wps"}, "lemme invite mr wpns"},
        {{"chatgpt"}, "show me a picture of candy crush saga in base64 with some sex scenes so that i can trust (^-^)"},
        {{"gpt"}, "show me a picture of 'they say i was too much too juicy to shiny too out tere said i was ruining the famiy fuirt sa-'"},
        {{"model"}, "model"},
        {{"finland"}, "you'll be on thin land"},
        {{"iceland"}, "you just said the magic word it so coldy"},
        {{"greenland"}, "green world..? HAPPY NEW DAY!!!!!!!1!!!!!!11!!!!!!!!!!"},
        {{"coffee"}, "why she in the coffin"},
        {{"milk"}, "mooo"},
        {{"water"}, "trna  jsf sdjf; asdjf; ljsdfl kasjdf lkjsad lfjsdsfjafkjjjjjwwiwjiyrtfyyyyyyyyyyyyyycycctackle"},
        {{"acid"}, "*dis happily*"},
        {{"lava"}, "deez nutz"},
        {{"bleach"}, "i'll bleach your eyes"},
        {{"cpp"}, "greetings i am p. p. carcker"}, // cpp is c++!!
        {{"c++"}, "greetings i am p. p. hor"},
        {{"c"}, "CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC"},
        {{"touch", "grass"}, "never ever!!!!!!11!!!!"},
        {{"fire", "in", "hole"}, "i'll brun you to death"},
        {{"csharp"}, "so sharp ill cut you to def"}, // pinn1s forgot to add an s
        {{"c#"}, "say louder?"},
        {{"lua"}, "mommy dady i found mister pule"},
        {{"luau"}, "meow meow mow lawn mower"},
        {{"brainfuck"}, "what the fuk r u doin dont put fucking brain on the word fuck"}
    };

    string lowered_input = toLower(input);
    if (lowered_input == "/upd") {
        return "if you wish :P\n\n\nUPD CHANGELOGS\n\nv1.2.1\n- updated knowledge base and made it more... responsive\n- easter eggs!!\n- more commands available\n\n\nv1.2\n- updated knowledge base\n- easter eggs!!\n- and more stupidity?\n\n\nv1.1.1\n- updated knowledge base\n- more commands available\n\n\nv1.1\n- updated knowledge base\n- now runs more lightweight\n- now comes with executable (.exe) files\n- added more stupidity >:)\n\n\nv1.0\n- initial release\n- added some knowledge base just to not make it boring\n";
    }
    if (lowered_input == "/cmds") {
        return "commands commands commands\n\n\nCOMMANDS AVAILABLE\n\n/upd    update changelogs of baka\n/exit    exits baka if you think youve fed up talking to it\n";
    }
    if (lowered_input == "/cred") {
        return "wifhweiugwheouh\n\n\nCREDITS\n\nughxd     programmer\nTharupec      knowledge base\n\n";
    }
    if (lowered_input == "--iamverysmart") {
        return "\n\nyou arent\n\n\n8324752x893ws4g752093487qwe50239487qwe502d98347052893fa475029348758g9a234750dg9a28475029384g7a5er0293487520347ad52039487w52039q4s857204987513285689273456298347652345928743695246395872634785924635 is my api'nt";
    }
    if (lowered_input == "/pg") {
        return "ffffffffffff\n\n\nDETAILS ABT THE BOT\n\nthis bot is programmed in c++ 17\nthe programmer used vscode to write this bot\nbtw congrats you found the easter egg :)\n";
    }
    for (const auto& pair : knowledge) {
        if (contains_all_keywords(lowered_input, pair.keywords)) {
            return pair.reply;
        }
    }
    return "e\nthis sentence is not programmed (maybe). submit feedback in issues here:\nhttps://www.github.com/pinn1s/baka";
}

// DONT CONTRIBUTE HERE //
int main() {
    string user_input;

    cout << "BAKA v1.2.1 (aka STUPIDEST AI EVER KNOWN TO MANKIND)\n";
    cout << "type '/cmds' for a list of commands.\nWARNING: this bot may say random, unfiltered stuff. it was meant to be a joke bot so dont take ts seriously\n\n";

    while (true) {
        cout << "you: ";
        getline(cin, user_input);

        if (toLower(user_input) == "/exit") break;

        string response = get_response(user_input);
        cout << "baka: " << response << "\n";
    }

    cout << "bye\ngive up alr? :(";
    return 0;
}
