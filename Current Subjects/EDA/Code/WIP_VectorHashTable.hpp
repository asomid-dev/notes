#include <vector>
using namespace std;

/*
*     █████╗ ███████╗ ██████╗     ██╗  ██╗ █████╗ ███████╗██╗  ██╗    ████████╗ █████╗ ██████╗ ██╗     ███████╗
*    ██╔══██╗██╔════╝██╔═══██╗    ██║  ██║██╔══██╗██╔════╝██║  ██║    ╚══██╔══╝██╔══██╗██╔══██╗██║     ██╔════╝
*    ███████║███████╗██║   ██║    ███████║███████║███████╗███████║       ██║   ███████║██████╔╝██║     █████╗
*    ██╔══██║╚════██║██║   ██║    ██╔══██║██╔══██║╚════██║██╔══██║       ██║   ██╔══██║██╔══██╗██║     ██╔══╝
*    ██║  ██║███████║╚██████╔╝    ██║  ██║██║  ██║███████║██║  ██║       ██║   ██║  ██║██████╔╝███████╗███████╗
*    ╚═╝  ╚═╝╚══════╝ ╚═════╝     ╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝       ╚═╝   ╚═╝  ╚═╝╚═════╝ ╚══════╝╚══════╝
*/

template <typename Key, typename Value>
class VectorHashTable {
    private:
        int m;
        std::vector<std::vector<std::pair<Key, Value> > > T;

        int hashFunction(const Key& k) const {
            return std::hash<Key>{}(k) % m;
        }

    public:
        VectorHashTable(int size) : m(size) {
            T.resize(m);
        }

        ~VectorHashTable(){
            for (int i = 0; i < T.size(); i++){
                auto& bucket = T[i];
                while (!bucket.empty()){
                    bucket.pop_back();
                }
            }
        }

        void insert(const Key& k, const Value& v){
            int index = hashFunction(k);
            auto& bucket = T[index];

            for (auto& p : bucket){
                if (p.first == k){
                    p.second = v;
                    return;
                }
            }

            bucket.push_back({k, v});
        }

        Value* consult(const Key& k) {
            int index = hashFunction(k);
            auto& bucket = T[index];

            for (auto& p : bucket) {
                if (p.first == k) {
                    return &p.second;
                }
            }
            return nullptr;
        }

        bool remove(const Key& k){
            int index = hashFunction(k);
            auto& bucket = T[index];

            for (int i = 0; i < bucket.size(); i++){
                if (bucket[i].first == k){
                    bucket[i] = bucket.back();
                    bucket.pop_back();
                    return true;
                }
            }
            return false;
        }
};
