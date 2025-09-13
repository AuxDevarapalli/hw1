#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

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
void ULListStr::push_back (const std::string& val){
  //empty list
  if (size_ == 0){
    Item* ender = new Item();
    ender->val[0] = val;
    ender->prev = nullptr;
    ender->next = nullptr;
    ender->first = 0;
    ender->last = 1;
    tail_ = head_ = ender;
    size_++;
    return;
  }
  //with no space at end
  if (tail_->last==ARRSIZE){ //TA: change to ARRSIZE
    size_++;
    Item* newEnd = new Item();
    newEnd->val[0]=val;
    newEnd->next = nullptr;
    newEnd->first = 0;
    newEnd->last = 1;
    tail_->next = newEnd;
    newEnd->prev= tail_;
    tail_ = newEnd;
    return;
  }
  //space within that array
  tail_->val[tail_->last] = val;
  tail_->last +=1;
  size_++;
  

}
void ULListStr::pop_back(){
  //empty
  if(size_==0){
    return;
  }
  tail_->last--;
  //what if still items
  if (tail_->first!=tail_->last){
    size_-=1;
    return;
  }
  if(tail_->first==tail_->last){

    //when theres only 1 node
    Item* tempTail = tail_;
    if (tail_->prev==nullptr){
      delete tempTail;
      head_=tail_=nullptr;
      size_--;
      return;
    }
    //when there are 2 nodes
    Item* temp = tail_;
    if(head_==tail_->prev){
      //head_=tail_;
      tail_=head_;
      tail_->next=nullptr;
    }
    else{
      tail_=tail_->prev;
      tail_->next=nullptr;
    }
    delete temp;
  }
  size_--;
}
void ULListStr::push_front(const std::string& val){
  //empty. so if size=0, then etc. not size=arrsize-1 - no value
  if (size_==0){
    Item* ender = new Item();
    ender->val[0] = val;
    ender->prev = nullptr;
    ender->next = nullptr;
    ender->first = 0;
    ender->last = 1;
    tail_ = head_ = ender;
    size_++;
    return;
  }
  //no space at front
  if(head_->first==0){
    Item* newStart = new Item();
    newStart->prev = nullptr;
    newStart->next = head_;
    head_->prev = newStart;
    head_ = newStart;
    newStart->val[ARRSIZE-1]=val; //9 - 10-1 (arrsize = 10)
    newStart->first = ARRSIZE-1; //changed from 0 to that, TA said no hardcoding
    newStart->last = ARRSIZE; // TA said no hard coding
    size_++;
    return;
  }
  //there is space 
  head_->first -=1;
  head_->val[head_->first]=val;
  size_++;
}
void ULListStr::pop_front(){
  //empty
  if (size_==0){
    return;
  }
  head_->first +=1;
  if(head_->first!=head_->last){
    size_-=1;
    return;
  }
  //indication that node is empty
  if(head_->first==head_->last){
    Item* tempHead = head_;
    if(head_==tail_){
      delete tempHead;
      head_=nullptr;
      tail_=nullptr;
      size_-=1;
      return;
    }
    else{
      head_=head_->next;
    }
    delete tempHead;
    head_->prev=nullptr;
  }
  size_-=1;
}
std::string const & ULListStr::back() const{
  return (tail_->val[tail_->last-1]);
}
std::string const & ULListStr::front() const{

  return (head_->val[head_->first]);
}
std::string* ULListStr::getValAtLoc(size_t loc) const{//confused
  //if the value doesnt exist
  if (loc==size_ || loc>size_){
    return NULL;
  }
  Item* temp=head_;
  size_t counter=0;
  Item* found;
  while (temp!=NULL){
    size_t tempFirst = temp->first;
    size_t tempLast = temp->last;
    size_t prevCounter=counter;
    counter+= (tempLast-tempFirst);
    if(prevCounter <=loc && counter >loc){//removed =, double check
      found = temp;
      return &found->val[found->first + (loc-prevCounter)];
      break;
    }
    temp=temp->next;
  }
  return NULL;

}


void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
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
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
