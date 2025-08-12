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
    };

    string lowered_input = toLower(input);

    if (lowered_input == "/upd") {
        return "if you wish :P\n\n\nUPD CHANGELOGS\n\nv1.1\n- updated knowledge base\n- now runs more lightweight\n- now comes with executable (.exe) files\n- added more stupidity >:)\n\n\nv1.0\n- initial release\n- added some knowledge base just to not make it boring\n";
    }

    if (lowered_input == "/cmds") {
        return "commands commands commands\n\n\nCOMMANDS AVAILABLE\n\n/upd    update changelogs of baka\n/exit    exits baka if you think youve fed up talking to it\n";
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

    cout << "BAKA v1.1 (aka STUPIDEST AI EVER KNOWN TO MANKIND)\n";
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