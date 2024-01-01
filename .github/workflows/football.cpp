#include <iostream>
#include <cstring>

using namespace std;

struct Node
{
    char player_name[100];
    int jersey_number;
    int goal;
    int got_red_card;
    int got_yellow_card;
    float pass_accuracy;
    Node *next;
};

class Football
{
    Node *match_1;
    Node *match_2;

public:
    Football() : match_1(nullptr), match_2(nullptr) {}

    void player_info_add(int match);
    void show(int match);
    void search_player(int match);
    void performance();
    void edit(int match);
    void delete_player(int match);
    void sortPlayersByGoals();
    void merge(Node *&head, Node *left, Node *right);
    void mergeSort(Node *&head);
    void combineMatches(Node *match1, Node *match2, Node *&combinedList);
    void displaySortedPlayers(Node *head);
    Node *getMiddle(Node *head);
    void getBest11Players();
};

// Info Add Function
void Football::player_info_add(int match)
{
    Node *new_node;
    new_node = new Node;

    cout << "Enter Player Name: ";
    cin >> new_node->player_name;
    cout << endl;

    cout << "Enter Jersey Number: ";
    cin >> new_node->jersey_number;
    cout << endl;

    cout << "Enter Goal Figure: ";
    cin >> new_node->goal;
    cout << endl;

    cout << "Enter Red Card Figure: ";
    cin >> new_node->got_red_card;
    cout << endl;

    cout << "Enter Yellow Card Figure: ";
    cin >> new_node->got_yellow_card;
    cout << endl;

    cout << "Enter The Percentage of Pass Accuracy: ";
    cin >> new_node->pass_accuracy;
    cout << endl;

    new_node->next = NULL;

    // stack implementation

    if (match == 1)
    {
        new_node->next = match_1;
        match_1 = new_node;
    }
    else if (match == 2)
    {
        new_node->next = match_2;
        match_2 = new_node;
    }
    else
    {
        cout << "Invalid match number." << endl;
        delete new_node;
    }
}

// Display Function For Specific Match
void Football::show(int match)
{
    Node *temp = (match == 1) ? match_1 : match_2;

    if (temp == NULL)
    {
        cout << "No Info in the match list." << endl;
    }
    else
    {
        cout << "======================== Player Info list for Match-" << match << " ======================== " << endl;
        cout << endl;

        while (temp != NULL)
        {
            cout << "Player Name: " << temp->player_name << endl;
            cout << "Jersey Number: " << temp->jersey_number << endl;
            cout << "Goal Figure: " << temp->goal << endl;
            cout << "Red Card Figure: " << temp->got_red_card << endl;
            cout << "Yellow Card Figure: " << temp->got_yellow_card << endl;
            cout << "Pass accuracy: " << temp->pass_accuracy << endl;

            temp = temp->next;
            cout << "\n";
        }

        cout << "\n";
    }
}

// Search Function Using Player Name and Player Jersey Number
void Football::search_player(int match)
{
    char name[100];
    int number;

    cout << "Enter Name: ";
    cin >> name;
    cout << endl;

    cout << "Enter Jersey Number: ";
    cin >> number;
    cout << endl;

    Node *temp = (match == 1) ? match_1 : match_2;

    if (temp == NULL)
    {
        cout << "No Info available in Match-" << match << endl;
    }
    else
    {
        while (temp != NULL)
        {
            if (strcmp(temp->player_name, name) == 0 && temp->jersey_number == number)
            {
                cout << "\n>>>>>>>>>>>>>> Match-" << match << " <<<<<<<<<<<<<<" << endl;
                cout << "\nPlayer Name: " << temp->player_name << endl;
                cout << "Jersey Number: " << temp->jersey_number << endl;
                cout << "Goal Figure: " << temp->goal << endl;
                cout << "Red Card Figure: " << temp->got_red_card << endl;
                cout << "Yellow Card Figure: " << temp->got_yellow_card << endl;
                cout << "Pass accuracy: " << temp->pass_accuracy << endl;

                break;
            }

            temp = temp->next;
        }
    }
}

// Update Player Info
void Football::edit(int match)
{
    char name[100];
    int number;

    cout << "Enter Player Name: ";
    cin >> name;
    cout << endl;

    cout << "Enter Jersey Number: ";
    cin >> number;
    cout << endl;

    Node *temp = (match == 1) ? match_1 : match_2;

    if (temp == NULL)
    {
        cout << "There is nothing to Edit." << endl;
    }
    else
    {
        while (temp != NULL)
        {
            if (strcmp(temp->player_name, name) == 0 && temp->jersey_number == number)
            {
                cout << "Enter Update Player Name: ";
                cin >> temp->player_name;
                cout << endl;

                cout << "Enter Update Jersey Number: ";
                cin >> temp->jersey_number;
                cout << endl;

                cout << "Enter Update Goal Figure: ";
                cin >> temp->goal;
                cout << endl;

                cout << "Enter Update Red Card Figure: ";
                cin >> temp->got_red_card;
                cout << endl;

                cout << "Enter Update Yellow Card Figure: ";
                cin >> temp->got_yellow_card;
                cout << endl;

                cout << "Enter The Update Percentage of Pass Accuracy: ";
                cin >> temp->pass_accuracy;
                cout << endl;

                break;
            }

            temp = temp->next;
        }
    }
}

// Delete Function to Remove a Player Info
void Football::delete_player(int match)
{
    char name[100];
    int number;

    cout << "Enter Player Name: ";
    cin >> name;
    cout << endl;

    cout << "Enter Jersey Number: ";
    cin >> number;
    cout << endl;

    Node *temp = (match == 1) ? match_1 : match_2;

    if (temp == NULL)
    {
        cout << "No Info available in Match-" << match << endl;
    }
    else
    {
        Node *previous = NULL;

        while (temp != NULL)
        {
            if (strcmp(temp->player_name, name) == 0 && temp->jersey_number == number)
            {
                if (previous == NULL)
                {
                    // Removing the first node
                    if (match == 1)
                    {
                        match_1 = temp->next;
                    }
                    else
                    {
                        match_2 = temp->next;
                    }
                }
                else
                {
                    previous->next = temp->next;
                }

                delete temp;
                cout << "Player Deleted." << endl;
                return;
            }

            previous = temp;
            temp = temp->next;
        }

        cout << "Player not found in Match-" << match << endl;
    }
}

// Performance Function
void Football::performance()
{
    char name[100];
    int number;

    cout << "Enter Name: ";
    cin >> name;
    cout << endl;

    cout << "Enter Jersey Number: ";
    cin >> number;
    cout << endl;

    Node *temp1 = match_1;
    Node *temp2 = match_2;

    Node *playerInfo1 = nullptr;
    Node *playerInfo2 = nullptr;

    // Search for the player in Match 1
    while (temp1 != nullptr)
    {
        if (strcmp(temp1->player_name, name) == 0 && temp1->jersey_number == number)
        {
            playerInfo1 = temp1;
            break;
        }
        temp1 = temp1->next;
    }

    // Search for the player in Match 2
    while (temp2 != nullptr)
    {
        if (strcmp(temp2->player_name, name) == 0 && temp2->jersey_number == number)
        {
            playerInfo2 = temp2;
            break;
        }
        temp2 = temp2->next;
    }

    // Display the result
    cout << "-------------------------------------------Result--------------------------------------------------" << endl;
    cout << endl;

    if (playerInfo1 != nullptr)
    {
        cout << "Details for Match 1:" << endl;
        cout << "Player Name: " << playerInfo1->player_name << endl;
        cout << "Jersey Number: " << playerInfo1->jersey_number << endl;
        cout << "Goal Figure: " << playerInfo1->goal << endl;
        cout << "Red Card Figure: " << playerInfo1->got_red_card << endl;
        cout << "Yellow Card Figure: " << playerInfo1->got_yellow_card << endl;
        cout << "Pass accuracy: " << playerInfo1->pass_accuracy << endl;
        cout << endl;
    }
    else
    {
        cout << "Player not found in Match 1." << endl;
    }

    if (playerInfo2 != nullptr)
    {
        cout << "Details for Match 2:" << endl;
        cout << "Player Name: " << playerInfo2->player_name << endl;
        cout << "Jersey Number: " << playerInfo2->jersey_number << endl;
        cout << "Goal Figure: " << playerInfo2->goal << endl;
        cout << "Red Card Figure: " << playerInfo2->got_red_card << endl;
        cout << "Yellow Card Figure: " << playerInfo2->got_yellow_card << endl;
        cout << "Pass accuracy: " << playerInfo2->pass_accuracy << endl;
        cout << endl;
    }
    else
    {
        cout << "Player not found in Match 2." << endl;
    }
}

// Function to get the middle node of a linked list
Node *Football::getMiddle(Node *head)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    Node *slow = head;
    Node *fast = head->next;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

// Function to combine players from both matches into a single list
void Football::combineMatches(Node *match1, Node *match2, Node *&combinedList)
{
    Node *temp = nullptr;
    while (match1 != nullptr)
    {
        temp = match1->next;
        match1->next = combinedList;
        combinedList = match1;
        match1 = temp;
    }

    while (match2 != nullptr)
    {
        temp = match2->next;
        match2->next = combinedList;
        combinedList = match2;
        match2 = temp;
    }
}

// Function to display the sorted list of players
void Football::displaySortedPlayers(Node *head)
{
    cout << "Players sorted based on highest scorer (total goals):" << endl;

    Node *current = head;
    while (current != nullptr)
    {
        cout << "Player Name: " << current->player_name << endl;
        cout << "Jersey Number: " << current->jersey_number << endl;
        cout << "Total Goals: " << current->goal << endl;
        cout << "------------------------" << endl;

        current = current->next;
    }
}

void Football::merge(Node *&head, Node *left, Node *right)
{
    Node dummy;
    Node *current = &dummy;

    while (left != nullptr && right != nullptr)
    {
        if (left->goal >= right->goal)
        {
            current->next = left;
            left = left->next;
        }
        else
        {
            current->next = right;
            right = right->next;
        }
        current = current->next;
    }

    current->next = (left != nullptr) ? left : right;
    head = dummy.next;
}

void Football::mergeSort(Node *&head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return;
    }

    Node *middle = getMiddle(head);
    Node *nextToMiddle = middle->next;

    middle->next = nullptr;

    mergeSort(head);
    mergeSort(nextToMiddle);

    merge(head, head, nextToMiddle);
}

void Football::sortPlayersByGoals()
{
    Node *combinedList = nullptr;

    // Combine players from both matches into a single list
    combineMatches(match_1, match_2, combinedList);

    // Apply merge sort to sort the list by total goals in descending order
    mergeSort(combinedList);

    // Display the sorted list
    displaySortedPlayers(combinedList);
}

void Football::getBest11Players()
{
    Node *combinedList = nullptr;
    combineMatches(match_1, match_2, combinedList);

    // Apply merge sort to sort the list by total goals in descending order
    mergeSort(combinedList);

    // Display the best 11 players
    Node *current = combinedList;
    int count = 0;

    cout << "========================= Best 11 Players =========================" << endl;
    while (current != nullptr && count < 11)
    {
        cout << "Player Name: " << current->player_name << endl;
        cout << "Jersey Number: " << current->jersey_number << endl;
        cout << "Total Goals: " << current->goal << endl;
        cout << "------------------------" << endl;

        current = current->next;
        count++;
    }
}

int main()
{
    Football match;

    int choice = 0;
    while (choice != 10)
    {
        cout << "========================== Main Menu ==============================" << endl;
        cout << "1. Add Player Info." << endl;
        cout << "2. Display Match 1 Info." << endl;
        cout << "3. Display Match 2 Info." << endl;
        cout << "4. Search Specific Player Info." << endl;
        cout << "5. Performance of Specific Player." << endl;
        cout << "6. Edit Specific Player Info." << endl;
        cout << "7. Highest Scorer." << endl;
        cout << "9.Select Best 11 Players" << endl;
        cout << "8. Delete Specific Player Info." << endl;
        cout << "10. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int matchNumber;
            cout << "Enter Match Number (1 or 2): ";
            cin >> matchNumber;
            match.player_info_add(matchNumber);
            break;
        }
        case 2:
            match.show(1);
            break;
        case 3:
            match.show(2);
            break;
        case 4:
        {
            int matchNumber;
            cout << "Enter Match Number (1 or 2): ";
            cin >> matchNumber;
            match.search_player(matchNumber);
            break;
        }
        case 5:
            match.performance();
            break;
        case 6:
        {
            int matchNumber;
            cout << "Enter Match Number (1 or 2): ";
            cin >> matchNumber;
            match.edit(matchNumber);
            break;
        }
        case 7:
            match.sortPlayersByGoals();
            break;
        case 8:
        {
            int matchNumber;
            cout << "Enter Match Number (1 or 2): ";
            cin >> matchNumber;
            match.delete_player(matchNumber);
            break;
        }
        case 9:
            match.getBest11Players();
            break;

        case 10:
            cout << "********************* Exit Completed ******************" << endl;
            break;
        default:
            cout << "Please Enter a valid choice." << endl;
        }
    }

    return 0;
}
