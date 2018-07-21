class Node {
public:
    int start;
    int end;
    Node(int start, int end)
        :start{start}, end{end}
    {}
};

class MyCalendarTwo {
    vector < Node > bookings, doubleBookings;
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        
        for (auto const& node: doubleBookings) {
            if (start < node.end && end > node.start)
                return false;
        }
        
        for (auto const& node: bookings) {
            if (start < node.end && end > node.start)
                doubleBookings.push_back(
                    Node(max(start, node.start), min(end, node.end)));
        }
        
        bookings.push_back(Node(start, end));
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo obj = new MyCalendarTwo();
 * bool param_1 = obj.book(start,end);
 */
