#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "main.h"
#include <exception>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->GameWidget->setCurrentIndex(0);
    counter = 1;
}

MainWindow::~MainWindow()
{
    delete ui;
    vector<Item>().swap(Items);
    vector<Character>().swap(Characters);
}

class oobException : public exception{

    const char* what() const throw()
    {
        return "Error, trying to access invalid memory address\n";
    }
};


void MainWindow::on_ExitButton_clicked()
{
    QCoreApplication::quit();
}

void MainWindow::on_HTPButton_clicked()
{
    ui->GameWidget->setCurrentIndex(1);
}

void MainWindow::on_StartButton_clicked()
{
    ui->GameWidget->setCurrentIndex(2);
    createRooms();
    //play();
}

void MainWindow::on_ReturnButton_clicked()
{
     ui->GameWidget->setCurrentIndex(0);
}

void MainWindow::on_GoNorthButton_clicked(){
    go("north");
}

void MainWindow::on_GoEastButton_clicked(){
    go("east");
}

void MainWindow::on_GoWestButton_clicked(){
    go("west");
}

void MainWindow::on_GoSouthButton_clicked(){
    go("south");
}

void MainWindow::on_TalkButton_clicked(){
    Characters = a->getCharacterList();
    it = Characters.begin();
    for(int i = 0; i < a->numberOfCharacters(); i++)
    {
        if (ui->CharacterList->currentText() == Characters[i].shortDescription()){
            it += i;
            currentCharacter = &(*it);
            MainLobbyMethod(currentCharacter);
        }
    }
}

void MainWindow::on_pushButton_clicked()
{
    bool exists = false;
        bool Icheck = false;
        Items = currentRoom->getItemList();
        Characters = a->getCharacterList();
        it = Characters.begin();
        for(int i = 0; i < currentRoom->numberOfItems(); i++)
        {
            if (ui->ItemList->currentText() == Items[i].shortDescription())
            {
                Icheck = true;
                ptr = &Items[i];
            }
        }
        if(Icheck == true){
            if(counter == 6)
                ui->Descriptions->setText("Your Inventory is full!");
            else{
                for(int x = 0; x < InventorySize; x++)
                {
                    if(ui->ItemList->currentText() == Inventory[x].shortDescription())
                    {
                        exists = true;
                   }
                }
                if(exists == false)
                {
                    Inventory[counter] = *ptr;
                    counter++;
                    bubbleSort(Inventory, InventorySize);
                    ui->InventoryList->clear();
                    for (int i = 0; i < InventorySize; i++)
                        ui->InventoryList->addItem(Inventory[i].shortDescription());
                    currentRoom->removeItemFromRoom(ptr);
                }

            }

         }
}

void MainWindow::on_ExamineButton_clicked(){
        Items = currentRoom->getItemList();
        for(int i = 0; i < currentRoom->numberOfItems(); i++)
        {
            if (ui->ItemList->currentText() == Items[i].shortDescription())
            {
                ui->Descriptions->setText(Items[i].longDescription());
            }
        }
}


void MainWindow::on_Option1_clicked(){
    ui->DialogueBox->setText(currentCharacter->getDialogue(1));
}

void MainWindow::on_Option2_clicked(){
    ui->DialogueBox->setText(currentCharacter->getDialogue(2));
}

void MainWindow::on_Option3_clicked(){
    ui->DialogueBox->setText(currentCharacter->getDialogue(3));
}

void MainWindow::on_BackButton_clicked(){
    ui->GameWidget->setCurrentIndex(2);
}

void MainWindow::on_InventoryList_activated(const QString &arg1)
{
   for(int i = 0; i < InventorySize; i++)
   {
        if(arg1 == Inventory[i].shortDescription())
        {
           ui->Descriptions->setText(Inventory[i].longDescription());
        }

   }



}


void MainWindow::on_OpenMapButton_clicked()
{
    map = new Map(this);
    map->show();
}

void MainWindow::on_AccuseButton_clicked()
{
    check = new AccusationCheck(this);
    check->selected = currentCharacter;
    check->show();
}


void MainWindow::createRooms()  {
    Room *b, *c, *d, *e, *f, *g, *h, *i, *j;
    Item *soup, *rustedSword, *rock, *stick;
    Character *Gardener, *Butler;
    AnimateObject *Hamster;

    //Create Items
    soup = new Item("soup", 10, 2);
        soup->setLongDescription("On the oaken table you see a bowl of soup, steaming and filling the room with a pungent odour.");
        soup->setExamination(readFile(":/Text/Examinations/SoupExamination.txt"));
        soup->setWeight(500);
    rustedSword = new Item("sword", 10, 2);
        rustedSword->setLongDescription(readFile(":/Text/Sword.txt"));
        rustedSword->setWeight(1500);
    stick = new Item("stick", 1, 11);
        stick->setLongDescription("A broken treebranch lays snapped in the grass, it could be used as a crude weapon. ");
        stick->setWeight(750);
    rock = new Item("rock", 2, 22);
        rock->setLongDescription("A heavy rock is wedged in the dirt, it could fit in the palm of your hand. ");
        rock->setWeight(1000);

    //create Characters
    Gardener = new Character("The Gardener");
        Gardener->setDialogueLocation(":/Text/Examinations/Character Dialogue/Gardener Dialogue.txt");
        Gardener->setCharacterPic(":/Pictures/GardenerPic.jpg");
    Butler = new Character("The Butler");
        Butler->setDialogueLocation(":/Text/Examinations/Character Dialogue/Butler Dialogue.txt");
        Butler->setCharacterPic(":/Pictures/Butler.jpg");

    Hamster = new AnimateObject("Hamster");
         Hamster->setDialogueLocation(":/Text/Examinations/Character Dialogue/Hamster Dialogue.txt");
         Hamster->setCharacterPic(":/Pictures/HamsterPic.jpg");

    a = new MainLobby("The Main Lobby: ", soup, rustedSword);
        a->addCharacter(Gardener);
        a->addCharacter(Butler);
        a->addAnimateObject(Hamster);
        a->setLongDescription(readFile(":/Text/MainLobbyDescription.txt"));
    b = new Room("Dining Room: ");
    c = new Room("Billard Room: ");
    d = new Room("Hall: ", new Item("Picture", 3, 33));
    e = new Room("Lounge: ");
    f = new Room("Ball Room: ", new Item("Microphone", 4, 44));
    g = new Room("Kitchen: ");
    h = new Room("Conservatory: ", stick, rock);
    i = new Room("Study: ");
    j = new Room("Driveway: ");

//             (N, E, S, W)
    a->setExits(f, b, d, c);
    b->setExits(NULL, NULL, NULL, a);
    c->setExits(NULL, a, NULL, NULL);
    d->setExits(a, e, NULL, i);
    e->setExits(NULL, NULL, NULL, d);
    f->setExits(j, g, a, h);
    g->setExits(NULL, NULL, NULL, f);
    h->setExits(NULL, f, NULL, NULL);
    i->setExits(NULL, d, NULL, NULL);
    j->setExits(NULL, NULL, f, NULL);

       currentRoom = b;

       go("west");
}

void MainWindow::createInventory(){
    #ifdef InventorySize
    Item Inventory[InventorySize];
    Item inven, temp1, temp2, temp3, temp4, temp5;
     inven = Item("Inventory", 10, 10);
        inven.setLongDescription("This is your Inventory, click on an Item to examine it!");
    temp1 =  Item("You shouldnt be looking at this",10, 10);
        temp1.setLongDescription("You shouldnt be able to see this");
    temp2 = Item("You shouldnt be looking at this",10, 10);
        temp2.setLongDescription("You shouldnt be able to see this");
    temp3 =  Item("You shouldnt be looking at this",10, 10);
         temp3.setLongDescription("You shouldnt be able to see this");
    temp4 =  Item("You shouldnt be looking at this",10, 10);
         temp4.setLongDescription("You shouldnt be able to see this");
    temp5 =  Item("You shouldnt be looking at this",10, 10);
        temp5.setLongDescription("You shouldnt be able to see this");
    Inventory[0] = inven;
    Inventory[1] = temp1;
    Inventory[2] = temp2;
    Inventory[3] = temp3;
    Inventory[4] = temp4;
    Inventory[5] = temp5;

    #endif
}


namespace Victim{
    QString setText(QString input)
    {
        input = "The Victim was the young master of the house. Body has multiple stab wounds but no signs of a struggle.";
        return input;
    }
}

namespace MC{
    QString setText(QString input)
    {
        input = "You are Gruff McSaderton. The best detective in <INSERT CITY HERE>";
        return input;
    }
}

void MainWindow::on_VicButton_clicked()
{ 
    QString output = "";
    ui->Descriptions->setText(Victim::setText(output));
}


void MainWindow::on_MCButton_clicked()
{
    QString output = "";
    ui->Descriptions->setText(MC::setText(output));
}

void MainWindow::printWelcome() {
    ui->Descriptions->setText("start\n"
                              "'info' for help\n\n"+
                              currentRoom->longDescription()+"\n");
}


void MainWindow::go(string direction) {
    //Make the direction lowercase
    //transform(direction.begin(), direction.end(), direction.begin(),:: tolower);
    //Move to the next room
    Room* nextRoom = currentRoom->nextRoom(direction);
    if (nextRoom == NULL)
        ui->Descriptions->setText("There's nothing in that direction\n"+currentRoom->longDescription()+"\n");
    else
    {
        //ui->Descriptions->setText("Current Room: "+currentRoom->shortDescription()+"\nNext Room: "+nextRoom->shortDescription());
       currentRoom = nextRoom;
       ui->Descriptions->setText(currentRoom->longDescription()+"\n");
           //ui->Descriptions->setText("This isn't the main lobby");
       vector<Item> Items = currentRoom->getItemList();
       ui->ItemList->clear();
       ui->CharacterList->clear();
       for(int i = 0; i < currentRoom->numberOfItems(); i++)
           ui->ItemList->addItem(Items[i].shortDescription());
       if (MainLobby* temp = dynamic_cast<MainLobby*>(currentRoom)){
           ui->ItemList->clear();
           vector<Character> Characters = temp->getCharacterList();
           vector<Item> ItemsA = temp->getItemList();
           ui->Descriptions->setText(a->longDescription()+"\n");
           for(int i = 0; i < temp->numberOfCharacters(); i++){
               ui->CharacterList->addItem(Characters[i].shortDescription());
               if(i < a->numberOfItems())
                   ui->ItemList->addItem(ItemsA[i].shortDescription());
           }
       }
       DoorOpen;
    }
}

void MainWindow::MainLobbyMethod(Character *suspect){
    ui->GameWidget->setCurrentIndex(3);
    ui->DialogueBox->setText(suspect->getDialogue(0));
    QPixmap pix(suspect->getCharacterPic());
    int w = ui->label->width();
    int h = ui->label->height();
    ui->ProfilePic->setPixmap(pix.scaled(w/2, h/2, Qt::KeepAspectRatio));
}

QString MainWindow::readFile(QString fileLocation){
    QString ret = "";
    QFile file(fileLocation);
    if (!file.exists())
        qDebug() << file.fileName() << "does not exist";
     else if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
        cerr << "read in";
    QTextStream in(&file);
    in.seek(0);
    while (!in.atEnd()){
        QString line = in.readLine();
        ret = ret + line + "\n";
    }
    file.close();
    }
    else
    {
        qDebug() << "Couldn't open file";
    }
    return ret;
}
