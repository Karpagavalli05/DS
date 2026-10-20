
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    stack<string> history;

    history.push("google.com");
    history.push("youtube.com");
    history.push("abcsc.com");
    history.push("facebook.com");

    cout << "Browser History:\n";
    cout << "Google.com\n";
    cout << "Youtube.com\n";
    cout << "abcsc.com\n";
    cout << "Facebook.com\n";

    // First Back press
    if (!history.empty())
    {
        history.pop();
    }

    // Second Back press
    if (!history.empty())
    {
        history.pop();
    }

    if (!history.empty())
    {
        cout << "\nPage at the top after pressing Back twice: "
             << history.top() << endl;
    }
    else
    {
        cout << "\nBrowser history is empty.\n";
    }

    return 0;
}
