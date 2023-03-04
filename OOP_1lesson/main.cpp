#include <iostream>
#include <string>

using namespace std;

class Tree
{
    //Tree class
public:
    Tree(int typeTree, int typeWood, int typeLeaves)
    {
        treeType = typeTree;
        woodType = typeWood;
        leavesType = typeLeaves;
    }
    int getTreeType() { return treeType; }
    int getWoodType() { return woodType; }
    int getLeavesType() { return leavesType; }
    void setTreeType(int newTreeType) {treeType = newTreeType;}
    void setWoodType(int newWoodType) {woodType = newWoodType;}
    void setLeavesType(int newLeavesType) {leavesType = newLeavesType;}
protected:
    int treeType;
    int woodType;
    int leavesType;
};

class Furniture:protected Tree
{
private:
    int furnitureNumber;
public:

    Furniture(int typeTree, int typeWood, int typeLeaves, int furnitureType, int fuelT):Tree(typeTree, typeWood, typeLeaves)
    {
        treeType = typeTree;
        woodType = typeWood;
        leavesType = typeLeaves;
        furnitureNumber = furnitureType;
        fuelTime = fuelT;
    }
    void setNewTypeFurniture(int newType)
    {
        furnitureNumber = newType;
    }
    int getFurnitureNumber()
    {
        return furnitureNumber;
    }
    void checkDataBaseFurniture()
    {
        switch (furnitureNumber)
        {
        case 1:
            cout << "Current furniture is a bookshelf" << endl;
            break;
        case 2:
            cout << "Current furniture is a sofa" << endl;
            break;
        case 3:
            cout << "Current furniture is a dresser" << endl;
            break;
        default:
            cout << "Furniture is not selected! Use setNewTypeFurniture() to set!" << endl;
        }
    }
protected:
    int fuelTime;
};

class Chancellery:private Tree
{
private:
    string paperType;
    string cover;
public:
    Chancellery(int typeTree, int typeWood, int typeLeaves, string paper, string cov):Tree(typeTree, typeWood, typeLeaves)
    {
        paperType = paper;
        cover = cov;
    }

    void checkPaperType()
    {
        switch(leavesType)
        {
        case 1:
            paperType = "Bad paper";
            break;
        case 2:
            paperType = "Well paper";
            break;
        case 3:
            paperType = "Awesome quality";
            break;
        default:
            paperType = "Please, papers!";
        }
    }
    void checkCoverType()
    {
        switch(treeType)
        {
        case 1:
            cover = "Oak cover";
            break;
        case 2:
            cover = "Birch cover";
            break;
        case 3:
            cover = "Fir cover";
            break;
        default:
            cover = "No cover";
        }
    }
    void printInfo()
    {
        cout << "Cover: " << cover << ". Paper: " << paperType << endl;
    }
};

class Fuel:protected Furniture
{
public:

    Fuel(int typeTree, int typeWood, int typeLeaves, int furnitureType, int fuelT):Furniture(typeTree, typeWood, typeLeaves, furnitureType, fuelT)
    {
        treeType = typeTree;
        woodType = typeWood;
        leavesType = typeLeaves;
        setNewTypeFurniture(furnitureType);
        fuelTime = fuelT;
    }

    int checkFuelTime_sec()
    {
        switch(getFurnitureNumber())
        {
        case 1:
            return 600;
        case 2:
            return 1800;
        case 3:
            return 2400;
        default:
            return 0;
        }
    }
    void burned()
    {
        cout << "It's burned for " << fuelTime << " seconds!" << endl;
    }

};


int main()
{
    Tree newTree(1, 1, 1);
    newTree.setTreeType(10);
    cout << "Tree have parametres: " << newTree.getLeavesType() << ", " << newTree.getTreeType() << ", " << newTree.getWoodType() << endl;


    Furniture newFurn(2, 3, 1, 4, 5000);
    newFurn.checkDataBaseFurniture();
    newFurn.setNewTypeFurniture(1);
    newFurn.checkDataBaseFurniture();

    Chancellery oakSticks(1, 1, 2, "-", "Oak");
    oakSticks.printInfo();
    oakSticks.checkCoverType();
    oakSticks.checkPaperType();
    oakSticks.printInfo();

    Fuel newFuel(1, 1, 1, 1, 2000);
    newFuel.burned();

    return 0;
}
