#include <iostream>
#include <vector>

// لاحظ رمز & هنا! هذا يعني تمرير بالمرجع (نفس المصفوفة في الذاكرة)
void recursiveDive(std::vector<int>& mainChain, int level) {
    
    // شرط التوقف (قاع المحيط)
    if (level == 2) {
        std::cout << "--> [Level 2 - Bottom] Reached the bottom!\n";
        std::cout << "--> [Level 2 - Bottom] Modifying the array directly...\n";
        
        mainChain.clear();
        mainChain.push_back(78);
        mainChain.push_back(97);
        mainChain.push_back(100);
        
        // هنا تبدأ رحلة العودة (Unwinding)
        return; 
    }

    std::cout << "[Level " << level << "] Going to sleep... calling level " << level + 1 << "\n";

    // الاستدعاء العودي (لحظة القفز للأسفل)
    // الكود يتوقف هنا ولا يقرأ ما بعد هذا السطر حتى تعود الدالة من الأسفل!
    recursiveDive(mainChain, level + 1);

    // ==========================================
    // هنا لحظة الاستيقاظ! (The Wake Up Point)
    // ==========================================
    std::cout << "[Level " << level << "] Woke up! The array is now: ";
    for (size_t i = 0; i < mainChain.size(); ++i) {
        std::cout << mainChain[i] << " ";
    }
    std::cout << "\n";
}

int main() {
    std::vector<int> myChain;
    
    // مصفوفة عشوائية في المستوى الأول
    myChain.push_back(100);
    myChain.push_back(78);
    myChain.push_back(97);

    std::cout << "Starting the Dive...\n";
    
    // نبدأ الاستدعاء العودي من المستوى 1
    recursiveDive(myChain, 1);

    return 0;
}