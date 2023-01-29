#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

#include <iostream>

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL)
	{
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = (*head_).next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}

// pushback function
// this function will put object to list end
void ULListStr::push_back(const std::string &val) 

{
    
    this->size_ = this->size_ + 1; // increment item amount by 1

    // new item named i formed included 
    Item* i = new Item(); 


    //temp  to set to val value
    std::string temp;

    temp = val; //make temp
    (*i).val[(*i).last] = temp;
    
    (*i).last = (*i).last + 1; // final object is incremented 



    // check list
    // empty or not
    if (!(this->head_ != nullptr)) 
    {

        // head and tails are to the begging and final items on the list 
        // both are = to i
        this->head_ = i;

        // set tail_ equal to the new item
        this->tail_ = i;

        // final return
        return;
    }

		this->tail_->next = i;

    (*i).prev = this->tail_;

    this->tail_ = i;
}



// popback function
// this function will take fof item from the end of list
void ULListStr::pop_back() 
{
	if (this->size_ <= 0) { return; }

    (*this).size_ =  (*this).size_  -1; // list size is decremented

    Item* now = this->tail_;
  
    this->tail_ = (*this->tail_).prev; // change tail value to previous tail

    //search value of tail for null pointer
    if ((*this).tail_) 

    {
      (*this->tail_).next = nullptr;
    } 

    if (!((*this).tail_))
// clear 
  { 
   head_ = nullptr;
   }

    (*now).last = (*now).last - 1;  //decrement the final value

    delete now; // remove the item 
}

// include new item to begining 
void ULListStr::push_front(const std::string &val) 
{

    (*this).size_ = (*this).size_ + 1; // increment this size
    Item* i = new Item();

    (*i).val[(*i).last] = val;// provide the value to the new object's value


    // check list
    // empty or not
    if (!((*this).head_ != nullptr)) 
    {

        // head and tails are to the begging and final items on the list 
        // both are = to i
        (*this).head_ = i;

        // set tail_ equal to the new item
        (*this).tail_ = i;

        // final return
        return;
    }

		(*this).head_->prev = i;

    (*i).next = this->head_;

    (*this).head_ = i;
}

// pop front 
void ULListStr::pop_front()  // this functions clear item in front
{ 
    (*this).size_ =  (*this).size_ -1; // decrement

    // locate the head 
    // the one we have now
    Item* now = this->head_;


    (*this).head_ = (*this->head_).next; // head gets changed to next value


  // check for null pointer value on head and tails
    if (!((*this).tail_))
    {
      // set tail null pointer to tail
      tail_ = nullptr;
    }

    if (!((*this).head_))
    {
      // set head null pointer to tail
      head_ = nullptr;

    }

    // deallocate last item

    delete now;
}


std::string const &ULListStr::front() const 
{

    std::string temp;
    temp = (*this->head_).val[(*this->head_).first];

    //return begining object
    return temp;
}


std::string *ULListStr::getValAtLoc(size_t loc) const // location value returner func
{
    Item* now = this->head_;

    for (size_t a = 0; a<loc; a++) 
    {
        now = (*now).next; // change value to new next
        // locate if list has more amount than objects present 
        if (!now) 
        {
          return nullptr;
        }
    }
    return (*now).val;
}


std::string const &ULListStr::back() const 
{

    std::string temp;
    temp = (*this->tail_).val[(*this->tail_).last-1];

    // return final object
    return temp;
}



