#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string toLower(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
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
    static vector<Response> knowledge = {
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
        {{"696926"}, "code unlocked! let me give you some knowledge (bc im not baka anymore)\n\nπ (pi) is a number which after the decimal lies an infinite amount of numbers. right now, scientists have found out approximately three hundred trillion digits as of may 2025. the number pi originally was discovered when people divided the circumfrence of a circle with the diameter of a circle and they found out that it was irrational. plus, they also found out that it was also approximately equal to 22 divided by 7 and calculated the first digits as 3.1415926. rn, due to moden technology, they finally spiked up from just 7 digts to a whopping 300 trillion digits. but scientists declared that pi will never end."}
    };

    string lowered_input = toLower(input);

    if (lowered_input == "/upd") {
        return "if you wish :P\n\n\nUPD CHANGELOGS\n\nv1.2\n- updated knowledge base\n- easter eggs!!\n- and more stupidity?\n\n\nv1.1.1\n- updated knowledge base\n- more commands available\n\n\nv1.1\n- updated knowledge base\n- now runs more lightweight\n- now comes with executable (.exe) files\n- added more stupidity >:)\n\n\nv1.0\n- initial release\n- added some knowledge base just to not make it boring\n";
    }

    if (lowered_input == "/cmds") {
        return "commands commands commands\n\n\nCOMMANDS AVAILABLE\n\n/upd    update changelogs of baka\n/exit    exits baka if you think youve fed up talking to it\n";
    }

    if (lowered_input == "/cred") {
        return "wifhweiugwheouh\n\n\nCREDITS\n\nughxd     programmer\nTharupec      knowledge base\n\n";
    }

    if (lowered_input == "--iamverysmart") {
        return "\n\n        _            _        _           _   _        _  \n       / /\         /\ \     /\ \       /\ \ /\ \     /\_\n      / /  \       /  \ \    \ \ \     /  \ \\ \ \   / / /\n     / / /\ \__   / /\ \ \   /\ \_\   / /\ \ \\ \ \_/ / / \n    / / /\ \___\ / / /\ \_\ / /\/_/  / / /\ \ \\ \___/ /  \n    \ \ \ \/___// / /_/ / // / /    / / /  \ \_\\ \ \_/   \n     \ \ \     / / /__\/ // / /    / / /    \/_/ \ \ \    \n _    \ \ \   / / /_____// / /    / / /           \ \ \   \n/_/\__/ / /  / / /   ___/ / /__  / / /________     \ \ \  \n\ \/___/ /  / / /   /\__\/_/___\/ / /_________\     \ \_\ \n \_____\/   \/_/    \/_________/\/____________/      \/_/  \n";
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

int main() {
    string user_input;

    cout << "BAKA v1.2 (aka STUPIDEST AI EVER KNOWN TO MANKIND)\n";
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
