struct Node{
        public:
        int key,value,cnt;
        
        Node* next;
        Node* prev;
        Node(int _key,int _val)
        {
           key=_key;
           value=_val;
            cnt=1;
        }
    };
    struct List{
        Node* head;
         Node* tail;
        int size;
        
        List()
        {
            head=new Node(0,0);
             tail=new Node(0,0);
            head->next=tail;
            tail->prev=head;
            size=0;
        }
        void addnode(Node* node)
       {
        Node *temp=head->next;
        node->next=temp;
        node->prev=head;
        head->next=node;
        temp->prev=node;
            size++;
      }
       void deletenode(Node* delnode)
       {
        Node *delprev=delnode->prev;
        Node *delnext=delnode->next;
         delprev->next=delnext;
         delnext->prev=delprev;
         size--;
       }
    };
class  LFUCache{
    map<int,Node*>keyNode;
     map<int,List*>freqListMap;
    
    int maxsizecache;
    int minfreq;
    int cursize;
public:
    LFUCache(int capacity) {
        maxsizecache=capacity;
        minfreq=0;
        cursize=0;
    }
    void updatefreqlistmap(Node* node)
    {
        keyNode.erase(node->key);
        freqListMap[node->cnt]->deletenode(node);
        
        if(node->cnt==minfreq && freqListMap[node->cnt]->size==0) minfreq++;
        
        List* nexthigherfreqlist=new List();
        if(freqListMap.find(node->cnt+1)!=freqListMap.end())
            nexthigherfreqlist=freqListMap[node->cnt+1];
          
        node->cnt+=1;
         nexthigherfreqlist->addnode(node);
        freqListMap[node->cnt]=  nexthigherfreqlist;
        keyNode[node->key]=node;
        
    }
                                
    
    int get(int key) {
         if(keyNode.find(key)!=keyNode.end())
        {
            Node* node=keyNode[key];
            int res=node->value;
           updatefreqlistmap(node);
            return res;
        }
        return -1;
        
    }
    
    void put(int key, int value) {
        if(maxsizecache==0) return;
         if(keyNode.find(key)!=keyNode.end())
        {
            Node* node=keyNode[key];
           node->value=value;
           updatefreqlistmap(node);
             
            
        }
        else
        {
            if(cursize==maxsizecache)
            {
                List* list=freqListMap[minfreq];
                keyNode.erase(list->tail->prev->key);
                freqListMap[minfreq]->deletenode(list->tail->prev);
                cursize--;
            }
             cursize++;
            minfreq=1;
            List* listfreq=new List();
             if(freqListMap.find(minfreq)!=freqListMap.end())
                 listfreq=freqListMap[minfreq];
            
            
            Node* node=new Node(key,value);
            listfreq->addnode(node);
            keyNode[key]=node;
            freqListMap[minfreq]=listfreq;
        }
    }
};


/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */