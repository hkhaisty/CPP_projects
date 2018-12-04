#ifndef LAB_7_2_BAG_H
#define LAB_7_2_BAG_H

typedef int bag_type;

class Bag {
private:
    int count;
    bag_type data[20];

public:
    Bag();
    bool insert(bag_type);
    bool remove(bag_type);
    int size();
    void clear();
    bool inbag(bag_type);

};

#endif //LAB_7_2_BAG_H
