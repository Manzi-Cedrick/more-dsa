#include <iostream>
#include <vector>

using namespace std;

class Candidate
{
private:
    int _id;
    string firstName;
    string lastName;
    int nationalId;
    string motto;
    int voteCount;

public:
    Candidate(int id, const string &firstName, const string &lastName, int nationalId, const string &motto)
        : _id(id), firstName(firstName), lastName(lastName), nationalId(nationalId), motto(motto), voteCount(0) {}

    int getId() const
    {
        return _id;
    }

    string getFirstName() const
    {
        return firstName;
    }

    string getLastName() const
    {
        return lastName;
    }

    int getNationalId() const
    {
        return nationalId;
    }

    string getMotto() const
    {
        return motto;
    }

    int getVoteCount() const
    {
        return voteCount;
    }

    int incrementVote()
    {
        return voteCount++;
    }
};

class CandidateList
{
private:
    vector<Candidate> candidates;

public:
    void addCandidates(const Candidate &candidate)
    {
        candidates.push_back(candidate);
    }

    void listCandidates() const
    {
        for (size_t i = 0; i < candidates.size(); i++)
        {
            cout << "ID: " << candidates[i].getId()
                 << ", First name: " << candidates[i].getFirstName()
                 << ", Last name: " << candidates[i].getLastName()
                 << ", National Id: " << candidates[i].getNationalId()
                 << ", Motto: " << candidates[i].getMotto()
                 << ", Vote count: " << candidates[i].getVoteCount()
                 << endl;
        }
    }

    void voteForCandidate(const string &firstName, const string &lastName)
    {
        for (size_t i = 0; i < candidates.size(); i++)
        {
            if (candidates[i].getFirstName() == firstName && candidates[i].getLastName() == lastName)
            {
                candidates[i].incrementVote();
                cout << "Vote done !" << endl;
                return;
            }
        }
        cout << "Candidate not found!" << endl;
    }

    void reportWinner()
    {
        if (candidates.empty())
        {
            cout << "No candidates available! " << endl;
            return;
        }

        const Candidate *winner = &candidates[0];
        for (size_t i = 0; i < candidates.size(); i++)
        {
            if (candidates[i].getVoteCount() >= winner->getVoteCount())
            {
                winner = &candidates[i];
            }
        }

        cout << "Winner is: " << winner->getFirstName() << " " << winner->getLastName()
             << " with " << winner->getVoteCount() << " votes."
             << endl;
    }
};

int main()
{
    cout << "-------------------------------------------------------- " << endl;
    cout << "*                   SIMPLE VOTING SYSTEM               *" << endl;
    cout << "-------------------------------------------------------- " << endl;

    CandidateList candidatelist;

    Candidate candidate1(1, "Paul", "Kagame", 1199608004, "FPR, Inkingi y'iterambere! ");
    Candidate candidate2(3, "Frank", "Habineza", 1199808004, "Vision y' U Rwanda Rushya");
    Candidate candidate3(4, "Phillipe", "MpawiMana", 1200008004, "Politike Ihamye");

    candidatelist.addCandidates(candidate1);
    candidatelist.addCandidates(candidate2);
    candidatelist.addCandidates(candidate3);

    cout << "List of candidates:" << endl;
    candidatelist.listCandidates();

    while (true)
    {
        cout << "Enter command (vote <firstname> <lastname>, report, exit): ";
        string command;
        cin >> command;

        if (command == "vote")
        {
            string firstName, lastName;
            cin >> firstName >> lastName;
            cout << "Selected: " << firstName << " " << lastName << endl;
            candidatelist.voteForCandidate(firstName, lastName);
        }
        else if (command == "report")
        {
            cout << "----------------------------- Generating report --------------------------" << endl;
            candidatelist.reportWinner();
        }
        else if (command == "exit")
        {
            break;
        }
        else
        {
            cout << "Invalid type of command!" << endl;
        }
    }

    return 0;
}