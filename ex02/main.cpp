




// #include "PmergeMe.h"



// int main(int ac, char **av)
// {

//     if(ac < 2)
//         throw PmergeMe::InvalidArg();
//     try
//     {
//         PmergeMe obj;
//         obj.parseInput(av);

//         obj.printVec("Before: ");
//         std::cout << "Total elements parsed: " << obj.getSize() << std::endl;
//     }
//     catch(const std::exception &e)
//     {
//         std::cout <<  e.what() << std::endl;
//     }
    
// }


#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

// دالة مساعدة لطباعة الحاويات
template <typename Container>
void printContainer(const Container& c, const std::string& name) {
    std::cout << name << ": ";
    for (typename Container::const_iterator it = c.begin(); it != c.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main() {
    // تخيل أن هذه أوزان صناديق عشوائية في مستودع
    double raw_weights[] = {45.5, 12.0, 89.1, 33.3, 70.2, 20.0};
    size_t size = sizeof(raw_weights) / sizeof(raw_weights[0]);

    // سنستخدم std::vector لتوضيح المنطق
    std::vector<double> main_chain;
    std::vector<double> pending;

    // 1. مرحلة التقسيم (Pairing and Splitting)
    for (size_t i = 0; i < size; i += 2) {
        double first = raw_weights[i];
        double second = raw_weights[i + 1];

        // نضع الوزن الأكبر في السلسلة الرئيسية والأصغر في الانتظار
        if (first > second) {
            main_chain.push_back(first);
            pending.push_back(second);
        } else {
            main_chain.push_back(second);
            pending.push_back(first);
        }
    }

    // ملاحظة هامة: في خوارزمية المشروع الخاصة بك، ترتيب السلسلة الرئيسية
    // يجب أن يتم بشكل عودي (Recursion) وليس باستخدام std::sort
    // استخدمت std::sort هنا فقط لتجهيز السلسلة للمرحلة التالية في هذا المثال
    std::sort(main_chain.begin(), main_chain.end());

    printContainer(main_chain, "Sorted Main Chain (Winners)");
    printContainer(pending, "Pending Elements (Losers)");

    // 2. مرحلة الإدراج باستخدام البحث الثنائي (Binary Search Insertion)
    for (size_t i = 0; i < pending.size(); ++i) {
        // std::lower_bound يعيد Iterator يشير إلى المكان الصحيح للإدراج
        // لضمان بقاء الحاوية مرتبة
        std::vector<double>::iterator pos = std::lower_bound(main_chain.begin(), main_chain.end(), pending[i]);
        
        // عملية الإدراج الفعلية (Insertion)
        main_chain.insert(pos, pending[i]);
    }

    printContainer(main_chain, "Final Sorted Weights (Vector)");

    std::cout << "-----------------------------------" << std::endl;

    // يمكنك فعل الشيء نفسه تماماً باستخدام std::deque
    // هذا يثبت أن الواجهة البرمجية متطابقة للعمليتين
    std::deque<double> final_deq(main_chain.begin(), main_chain.end());
    printContainer(final_deq, "Final Sorted Weights (Copied to Deque)");

    return 0;
}