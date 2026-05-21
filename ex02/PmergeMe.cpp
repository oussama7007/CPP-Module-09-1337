


#include "PmergeMe.h"


PmergeMe::PmergeMe()
{

}
PmergeMe::PmergeMe(const PmergeMe& other) : vec(other.vec) , deq(other.deq)
{
}

PmergeMe & PmergeMe::operator=(const PmergeMe& other)
{
    if(this != &other)
    {
        vec = other.vec;
        deq = other.deq;
    }
    return *this;
}

PmergeMe::~PmergeMe()
{
}

size_t PmergeMe::getSize() const
{
    return vec.size();
}


const char * PmergeMe::InvalidArg::what() const throw()
{
    return "Error: No arguments passed";
}
const char * PmergeMe::InvalidInput::what () const throw()
{
    return "Error: Invalid character in sequence";
}

const char *PmergeMe::OutofRange::what() const throw()
{
    return "Error: Number out of range";
}
void PmergeMe::fordJohnsonDeque(std::deque<int>& arr)
{

    if (arr.size() <= 1) 
        return;

    int straggler = -1;
    bool hasStraggler = false;

    if (arr.size() % 2 != 0) {
        straggler = arr.back();
        arr.pop_back();       
        hasStraggler = true;
    }

    std::deque< std::pair<int, int> > pairs;
    for (size_t i = 0; i < arr.size(); i += 2) {
        if (arr[i] > arr[i+1]) {
            pairs.push_back(std::make_pair(arr[i], arr[i+1]));
        } else {
            pairs.push_back(std::make_pair(arr[i+1], arr[i]));
        }
    }

    std::deque<int> mainChain;
    for (size_t i = 0; i < pairs.size(); ++i) {
        mainChain.push_back(pairs[i].first);
    }

    fordJohnsonDeque(mainChain);


    std::deque<int> pend;
    for (size_t i = 0; i < mainChain.size(); ++i) {
        for (size_t j = 0; j < pairs.size(); ++j) {
            if (mainChain[i] == pairs[j].first) {
                pend.push_back(pairs[j].second);
                break; 
            }
        }
    }


    if (!pend.empty()) {
        mainChain.insert(mainChain.begin(), pend[0]);
    }

    size_t jacobIndex = 3; 
    size_t insertedCount = 1; 

    while (insertedCount < pend.size()) {
        size_t jNumber = getJacobsthalNumber(jacobIndex);
        
        size_t maxIndex = jNumber;
        if (maxIndex > pend.size()) {
            maxIndex = pend.size(); 
        }

        // Insert elements in REVERSE order for this batch
        for (size_t i = maxIndex; i > insertedCount; --i) {
            int valueToInsert = pend[i - 1]; 
            std::deque<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), valueToInsert);
            mainChain.insert(it, valueToInsert);
        }
        
        insertedCount = maxIndex;
        jacobIndex++;
    }

    // Insert Straggler if exists
    if (hasStraggler) {
        std::deque<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
        mainChain.insert(it, straggler);
    }

    // Update the original array
    arr = mainChain;
}

void PmergeMe::sortDeq()
{
    fordJohnsonDeque(this->deq);
}



void PmergeMe::fordJohnsonVector(std::vector<int>& arr)
{
    // 1. Base Case
    if (arr.size() <= 1) 
        return;

    int straggler = -1;
    bool hasStraggler = false;

    // 2. Handle Odd Number of Elements
    if (arr.size() % 2 != 0) {
        straggler = arr.back();
        arr.pop_back();       
        hasStraggler = true;
    }
    
    // 3. Create Pairs
    std::vector< std::pair<int, int> > pairs;
    for (size_t i = 0; i < arr.size(); i += 2) {
        if (arr[i] > arr[i+1]) {
            pairs.push_back(std::make_pair(arr[i], arr[i+1]));
        } else {
            pairs.push_back(std::make_pair(arr[i+1], arr[i]));
        }
    }

    // 4. Build Main Chain
    std::vector<int> mainChain;
    for (size_t i = 0; i < pairs.size(); ++i) {
        mainChain.push_back(pairs[i].first);
    }

    // 5. Recursion
    fordJohnsonVector(mainChain);

    // 6. Build Pend aligned with Main Chain
    std::vector<int> pend;
    for (size_t i = 0; i < mainChain.size(); ++i) {
        for (size_t j = 0; j < pairs.size(); ++j) {
            if (mainChain[i] == pairs[j].first) {
                pend.push_back(pairs[j].second);
                break; 
            }
        }
    }

    if (!pend.empty()) {
        mainChain.insert(mainChain.begin(), pend[0]);
    }

    size_t jacobIndex = 3; 
    size_t insertedCount = 1; 

    while (insertedCount < pend.size()) {
        size_t jNumber = getJacobsthalNumber(jacobIndex);
        
        size_t maxIndex = jNumber;
        if (maxIndex > pend.size()) {
            maxIndex = pend.size(); 
        }

        // Insert elements in REVERSE order for this batch
        for (size_t i = maxIndex; i > insertedCount; --i) {
            int valueToInsert = pend[i - 1]; 
            std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), valueToInsert);
            mainChain.insert(it, valueToInsert);
        }
        
        insertedCount = maxIndex;
        jacobIndex++;
    }

    // Insert Straggler if exists
    if (hasStraggler) {
        std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
        mainChain.insert(it, straggler);
    }

    // Update the original array! (This is what you were missing)
    arr = mainChain;
}
void PmergeMe::parseInput(char **av)
{
    for (int i = 1; av[i]; ++i)
    {
        std::string arg(av[i]);


        if (arg.empty() || arg.find_first_not_of(" \t") == std::string::npos)
            throw InvalidInput();

        std::istringstream iss(arg);
        std::string token;

        while (iss >> token)
        {

            if (token.find_first_not_of("0123456789+") != std::string::npos)
                throw InvalidInput();
                

            if (token.find('+') != std::string::npos && (token.find('+') != 0 || token.length() == 1))
                throw InvalidInput();

            long val = std::atol(token.c_str());

            if (val < 0 || val > 2147483647)
                throw OutofRange();

            int intVal = static_cast<int>(val);

           
            if (std::find(vec.begin(), vec.end(), intVal) != vec.end())
                throw std::invalid_argument("Error: Duplicate numbers are not allowed.");

            
            vec.push_back(intVal);
            deq.push_back(intVal);
        }
    }
}

size_t PmergeMe::getJacobsthalNumber(size_t n)
{
    // Base cases
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    size_t prev = 0;
    size_t curr = 1;
    size_t next = 0;
    
    // Calculate Jacobsthal number iteratively (Formula: J(n) = J(n-1) + 2*J(n-2))
    for (size_t i = 2; i <= n; ++i) {
        next = curr + 2 * prev;
        prev = curr;
        curr = next;
    }
    return curr;
}

void PmergeMe::printVec(const std::string& message) const
{
    std::cout << message; 
    
    
    size_t limit = vec.size() > 5 ? 5 : vec.size();

    for (size_t i = 0; i < limit; ++i)
    {
        std::cout << vec[i] << " ";
    }
    
    if (vec.size() > 5)
        std::cout << "[...]"; 

    std::cout << std::endl;
}

void PmergeMe::sortVec()
{
    fordJohnsonVector(this->vec);
}
