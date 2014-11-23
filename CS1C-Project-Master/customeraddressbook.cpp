#include "customeraddressbook.h"
#include "ui_customeraddressbook.h"
#include <QMessageBox>
#include <QString>
#include <QDebug>

CustomerAddressBook::CustomerAddressBook(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CustomerAddressBook),
    customerList()
{
    ui->setupUi(this);

    // name title
    setWindowTitle(tr("List of Customers"));

    // set read only text on construct
    ui->NameEdit->setReadOnly(true);
    ui->EmailEdit->setReadOnly(true);
    ui->AccountIdEdit->setReadOnly(true);
    ui->PasswordEdit->setReadOnly(true);

    ui->addButton->show();
    ui->submitButton->hide();
    ui->cancelButton->hide();

    //disable the next and previous buttons
    ui->nextCustomerButton->setEnabled(false);
    ui->prevCustomerButton->setEnabled(false);

    // disable the edit and remove buttons
    ui->editButton->setEnabled(false);
    ui->removeButton->setEnabled(false);


}

CustomerAddressBook::~CustomerAddressBook()
{
    delete ui;
}

void CustomerAddressBook::updateInterface (Mode mode)
{
    currentMode = mode;
    switch(currentMode)
    {
    case ADDING_MODE:
    case EDITING_MODE:
        // set read only text on construct
        ui->NameEdit->setReadOnly(false);
        ui->EmailEdit->setReadOnly(false);
        ui->AccountIdEdit->setReadOnly(false);
        ui->PasswordEdit->setReadOnly(false);

        ui->NameEdit->setFocus(Qt::OtherFocusReason);

        ui->addButton->setEnabled(false);
        ui->editButton->setEnabled(false);
        ui->removeButton->setEnabled(false);

        //disable the next and previous buttons
        ui->nextCustomerButton->setEnabled(false);
        ui->prevCustomerButton->setEnabled(false);

        // disable the edit and remove buttons
        ui->submitButton->show();
        ui->cancelButton->show();

        break;

    case NAVIGATION_MODE:

        if (customerList.isEmpty())
        {
            ui->NameEdit->clear();
            ui->EmailEdit->clear();
            ui->AccountIdEdit->clear();
            ui->PasswordEdit->clear();
        }

        int number = customerList.Size();

        // enables
        ui->editButton->setEnabled(number>=1);
        ui->removeButton->setEnabled(number>=1);
        ui->nextCustomerButton->setEnabled(number>1);
        ui->prevCustomerButton->setEnabled(number>1);

        ui->addButton->setEnabled(true);

        ui->submitButton->hide();
        ui->cancelButton->hide();
        break;
    }
}

void CustomerAddressBook::on_addButton_clicked()
{

    // store old information into variables
    // (in case they cancel submition)
    oldName = ui->NameEdit->text();
    oldEmail= ui->EmailEdit->text();
    oldId = ui->AccountIdEdit->text();
    oldPassword = ui->PasswordEdit->text();

    //disable the next and previous buttons
    ui->nextCustomerButton->setEnabled(false);
    ui->prevCustomerButton->setEnabled(false);

    // clear the fields, prepare for new entry
    ui->NameEdit->clear();
    ui->EmailEdit->clear();
    ui->AccountIdEdit->clear();
    ui->PasswordEdit->clear();

//    // allow user input
//    ui->NameEdit->setReadOnly(false);
//    ui->EmailEdit->setReadOnly(false);
//    ui->AccountIdEdit->setReadOnly(false);
//    ui->PasswordEdit->setReadOnly(false);

//    // access the name field (put cursor there)
//    ui->NameEdit->setFocus(Qt::OtherFocusReason);

//    // hide the add button, show the submit and cancel buttons.
//    ui->addButton->setEnabled(false);
//    ui->submitButton->show();
//    ui->cancelButton->show();

    updateInterface(ADDING_MODE);


}

void CustomerAddressBook::on_submitButton_clicked()
{
    // store new contact details in variables
    QString name = ui->NameEdit->text();
    QString email = ui->EmailEdit->text();
    QString idString = ui->AccountIdEdit->text();
    QString pass = ui->PasswordEdit->text();



    if (currentMode == ADDING_MODE)
    {

        Customer customer (name, email, idString.toLong(), pass);
        // check if any field is empty
        if (name.isEmpty())
        {
            QMessageBox::information(this, tr("Empty Field"),
                       tr("Please enter in a name."));
        }
        else if (email.isEmpty())
        {
            QMessageBox::information(this, tr("Empty Field"),
                       tr("Please enter in an email address."));
        }
        else if (idString.isEmpty())
        {
            QMessageBox::information(this, tr("Empty Field"),
                       tr("Please enter in an ID number."));
        }
        else if (pass.isEmpty())
        {
            QMessageBox::information(this, tr("Empty Field"),
                       tr("Please enter in a password."));
        }
        else
         {

            // check if the customer is not taken
           if (!customerList.isExist(customer))
           {

               customerList.Enqueue(customer);

               QMessageBox::information(this, tr("Add Successful"),
                tr("\"%1\" has been added to the customer list.").arg(name));

            }
           else
            {

               QMessageBox::information(this, tr("Add Unsuccessful"),
                tr("\"%1\" is already in your customer list.").arg(name));

            }


            //Restore the buttons to their normal state.
            ui->addButton->setEnabled(true);
            ui->submitButton->hide();
            ui->cancelButton->hide();

            // if list greater than one, enable the next and prev buttons
            int sizeList = customerList.Size();
            ui->nextCustomerButton->setEnabled(sizeList>1);
            ui->prevCustomerButton->setEnabled(sizeList>1);

            // set read only text on construct
            ui->NameEdit->setReadOnly(true);
            ui->EmailEdit->setReadOnly(true);
            ui->AccountIdEdit->setReadOnly(true);
            ui->PasswordEdit->setReadOnly(true);


         }
    }
    else if (currentMode == EDITING_MODE)
    {

//        Customer customer (oldName, oldEmail, oldId.toLong(), oldPassword);

        Customer newCust (name, email, idString.toLong(), pass);
        bool change = true;

         Customer* customerPtr = customerList.ReturnCustomerPtr(oldName);


        // change any updates!!
        if (oldName != name)
        {
            customerPtr->setUserName(name);
        }
        else if (oldEmail != email)
        {
            customerPtr->setEmail(email);
        }
        else if (oldId!= idString)
        {
            customerPtr->setAccountNum(idString.toLong());
        }
        else if (oldPassword!= pass)
        {
            customerPtr->setPassword(pass);
        }
        else if (customerList.isExist(newCust))
        {
            change = false;
            QMessageBox::information(this, tr("Edit Unsuccessful"),
              tr("Sorry, \"%1\" is already in your address book.").arg(name));
        }
        else
        {
            change = false;
            QMessageBox::information(this, tr("Edit Unsuccessful"),
              tr("No changes were made."));
        }

        if (change)
        {
            QMessageBox::information(this, tr("Edit Successful"),
              tr("\"%1\" has been edited in your address book.").arg(oldName));

        }

        customerPtr = NULL;
    }

    updateInterface(NAVIGATION_MODE);

}

void CustomerAddressBook::on_cancelButton_clicked()
{
    // reset all old data
    ui->NameEdit->setText(oldName);
    ui->EmailEdit->setText(oldEmail);
    ui->AccountIdEdit->setText(oldId);
    ui->PasswordEdit->setText(oldPassword);

//    // set read only text on construct
//    ui->NameEdit->setReadOnly(true);
//    ui->EmailEdit->setReadOnly(true);
//    ui->AccountIdEdit->setReadOnly(true);
//    ui->PasswordEdit->setReadOnly(true);

//    ui->addButton->setEnabled(true);
//    ui->submitButton->hide();
//    ui->cancelButton->hide();

//    // if list greater than one, enable the next and prev buttons
//    int sizeList = customerList.Size();
//    ui->nextCustomerButton->setEnabled(sizeList>1);
//    ui->prevCustomerButton->setEnabled(sizeList>1);

    updateInterface(NAVIGATION_MODE);
}

void CustomerAddressBook::on_nextCustomerButton_clicked()
{
    // get the next element, if out of range... re-loop...

    QString name = ui->NameEdit->text();
    Customer someCustomer;
    int index = customerList.FindCustomerLocation(name);

    // if index is the last one, start from beginning of list.
    if ((index+1) == customerList.Size())
    {
        someCustomer = customerList[0];
        ui->warningLabel->setText("You've reached the end of the list, re-starting from the beginning!");
    }
    else
    {
        // get next customer!
        someCustomer = customerList[++index];
        ui->warningLabel->setText("");

    }

    // update the fields with next customer!
    ui->NameEdit->setText(someCustomer.getUserName());
    ui->EmailEdit->setText(someCustomer.getEmail());
    ui->AccountIdEdit->setText(QString::number(someCustomer.getAccountNum()));
    ui->PasswordEdit->setText(someCustomer.getPassword());
}

void CustomerAddressBook::on_prevCustomerButton_clicked()
{
    // get the next element, if out of range... re-loop...

    QString name = ui->NameEdit->text();
    Customer someCustomer;
    int index = customerList.FindCustomerLocation(name);



    // if index is the first one, start from end of list.
    if (index == 0)
    {

        someCustomer = customerList[customerList.Size() - 1];
        ui->warningLabel->setText("You've reached the beginning of the list, re-starting from the end!");
    }
    else
    {
        // get next customer!
        someCustomer = customerList[--index];
        ui->warningLabel->setText("");
    }

    // update the fields with next customer!
    ui->NameEdit->setText(someCustomer.getUserName());
    ui->EmailEdit->setText(someCustomer.getEmail());

    ui->AccountIdEdit->setText(QString::number(someCustomer.getAccountNum()));
    ui->PasswordEdit->setText(someCustomer.getPassword());
}

void CustomerAddressBook::on_editButton_clicked()
{
    // store old information into variables
    // (in case they cancel edit)
    oldName = ui->NameEdit->text();
    oldEmail= ui->EmailEdit->text();
    oldId = ui->AccountIdEdit->text();
    oldPassword = ui->PasswordEdit->text();

    updateInterface(EDITING_MODE);
}

void CustomerAddressBook::on_removeButton_clicked()
{
    QString name = ui->NameEdit->text();
    QString email = ui->EmailEdit->text();
    QString idString = ui->AccountIdEdit->text();
    QString pass = ui->PasswordEdit->text();
    Customer customer (name, email, idString.toLong(), pass);
    if (customerList.isExist(customer))
    {
        int button = QMessageBox::question(this,
        tr("Confirm Remove"),
        tr("Are you sure you want to remove \"%1\"?").arg(name),
        QMessageBox::Yes | QMessageBox::No);

        if (button == QMessageBox::Yes)
        {
            on_prevCustomerButton_clicked();

            customerList.RemoveCustomer(customer);

            QMessageBox::information(this, tr("Remove Successful"),
                             tr("\"%1\" has been removed from your address book.").arg(name));
        }
    }

    updateInterface(NAVIGATION_MODE);
}