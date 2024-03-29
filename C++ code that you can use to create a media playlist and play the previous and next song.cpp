//kidus Berhanu
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
//

// Node structure for circular linked list
struct Node
{
    char title[50];
    char artist[50];
    Node *next;
};

// Function to create a new node
Node* getNewNode(char title[], char artist[])
{
    Node *newNode = new Node;
    strcpy(newNode->title, title);
    strcpy(newNode->artist, artist);
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of the list
void insertEnd(Node **head, char title[], char artist[])
{
    // If the list is empty, create a new node and make it the head
    if (*head == NULL)
    {
        *head = getNewNode(title, artist);
        (*head)->next = *head;
        return;
    }

    // Find the last node in the list
    Node *curr = *head;
    while (curr->next != *head)
        curr = curr->next;

    // Create a new node and insert it at the end of the list
    Node *newNode = getNewNode(title, artist);
    curr->next = newNode;
    newNode->next = *head;
}

// Function to play the next song in the playlist
void playNext(Node **head)
{
    // If the list is empty, there is nothing to play
    if (*head == NULL)
        return;

    // Play the next song in the playlist
    *head = (*head)->next;
}

// Function to play the previous song in the playlist
void playPrev(Node **head)
{
    // If the list is empty, there is nothing to play
    if (*head == NULL)
        return;

    // Find the last node in the list
    Node *curr = *head;
    while (curr->next != *head)
        curr = curr->next;

    // Play the previous song in the playlist
    *head = curr;
}

// Function to display the current song
void displayCurrent(Node *head)
{
    // If the list is empty, there is nothing to display
    if (head == NULL)
        return;

    // Display the current song
    cout << "Playing: " << head->title << " by " << head->artist << endl;
}

// Function to display the playlist
void displayPlaylist(Node *head)
{
    // If the list is empty, there is nothing to display
    if (head == NULL)
        return;

    // Display the playlist
    cout << "Playlist: " << endl;
    Node *curr = head;
    do
    {
        cout << curr->title << " by " << curr->artist << endl;
        curr = curr->next;
    } while (curr != head);
}

int main()
{
    Node *head = NULL;

    // Insert some songs into the playlist
    insertEnd(&head, "Song 1", "Artist 1");
    insertEnd(&head, "Song 2", "Artist 2");
    insertEnd(&head, "Song 3", "Artist 3");
    insertEnd(&head, "Song 4", "Artist 4");

    // Display the current song and the playlist
    displayCurrent(head);
    displayPlaylist(head);

    // Play the next song
    playNext(&head);

    // Display the current song and the playlist
    displayCurrent(head);
    displayPlaylist(head);

    // Play the previous song
    playPrev(&head);

    // Display the current song and the playlist
    displayCurrent(head);
    displayPlaylist(head);

    return 0;
}

