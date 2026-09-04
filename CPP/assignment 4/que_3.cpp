#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

/*
===============================================================================
EXPLANATION: WHY TEMPLATES MUST BE ENTIRELY IN THE HEADER OR ONE FILE
===============================================================================
Templates are compile-time code blueprints, not real functions. The compiler
generates machine code for a template only when it sees it instantiated with
a concrete type (e.g., DataBuffer<int>). If template definitions are separated
into a distinct .cpp file, that file compiles independently without knowing
which specific type variants the rest of the application requires, leading
to "undefined reference" linker errors.
*/

// ============================================================================
// PART A — Abstract DataProcessor Interface & Concrete Subclasses
// ============================================================================
class DataProcessor {
public:
    virtual void loadData(const string& source) = 0;
    virtual void processData() = 0;
    virtual void exportResult(const string& destination) = 0;
    virtual string processorType() const = 0;
    virtual int recordCount() const = 0;

    virtual void printSummary() const {
        cout << "Summary Report: Type = [" << processorType()
             << "], Records Loaded = " << recordCount() << endl;
    }
    virtual ~DataProcessor() = default;
};

// --- CSVProcessor ---
class CSVProcessor : public DataProcessor {
private:
    vector<string> records;
public:
    void loadData(const string& source) override {
        records.push_back("john,doe,25");
        records.push_back("jane,smith,30");
        records.push_back("alice,jones,22");
        records.push_back("bob,brown,28");
        records.push_back("charlie,green,35");
    }
    void processData() override {
        for (auto& row : records) {
            for (auto& ch : row) ch = toupper(ch);
        }
    }
    void exportResult(const string& destination) override {
        cout << "[CSV EXPORT -> " << destination << "] header" << endl;
        for (const auto& row : records) cout << "  " << row << endl;
    }
    string processorType() const override { return "CSV Processor"; }
    int recordCount() const override { return records.size(); }
};

// --- SensorStreamProcessor ---
class SensorStreamProcessor : public DataProcessor {
private:
    vector<double> readings;
    double meanVal = 0.0;
    double minVal = 0.0;
    double maxVal = 0.0;
public:
    void loadData(const string& source) override {
        readings.push_back(23.4); readings.push_back(21.8);
        readings.push_back(25.1); readings.push_back(36.6);
        readings.push_back(37.1); readings.push_back(38.2);
        readings.push_back(36.9); readings.push_back(24.8);
    }
    void processData() override {
        if (readings.empty()) return;
        double sum = 0.0;
        minVal = readings[0]; maxVal = readings[0];
        for (double val : readings) {
            sum += val;
            if (val < minVal) minVal = val;
            if (val > maxVal) maxVal = val;
        }
        meanVal = sum / readings.size();
    }
    void exportResult(const string& destination) override {
        cout << "[SENSOR EXPORT -> " << destination << "]" << endl;
        cout << "  Statistical Summary written successfully." << endl;
    }
    string processorType() const override { return "Sensor Stream Processor"; }
    int recordCount() const override { return readings.size(); }

    // Required getter added for the bonus section loop
    double getMean() const { return meanVal; }
};

// ============================================================================
// PART B — Class Template DataBuffer<T> (Circular Buffer)
// ============================================================================
template <typename T>
class DataBuffer {
private:
    T* data;
    int capacity;
    int head;
    int tail;
    int count;
public:
    DataBuffer(int cap) : capacity(cap), head(0), tail(0), count(0) {
        data = new T[capacity];
    }
    ~DataBuffer() { delete[] data; }

    bool isEmpty() const { return count == 0; }
    bool isFull() const { return count == capacity; }
    int size() const { return count; }

    void push(const T& value) {
        if (isFull()) {
            data[tail] = value;
            tail = (tail + 1) % capacity;
            head = (head + 1) % capacity;
        } else {
            data[tail] = value;
            tail = (tail + 1) % capacity;
            count++;
        }
    }
    T pop() {
        if (isEmpty()) throw underflow_error("Buffer is empty");
        T val = data[head];
        head = (head + 1) % capacity;
        count--;
        return val;
    }
    T peek() const {
        if (isEmpty()) throw underflow_error("Buffer is empty");
        return data[head];
    }

    template <typename U>
    friend ostream& operator<<(ostream& out, const DataBuffer<U>& buf);
};

template <typename U>
ostream& operator<<(ostream& out, const DataBuffer<U>& buf) {
    out << "[";
    int current = buf.head;
    for (int i = 0; i < buf.count; ++i) {
        out << buf.data[current];
        if (i < buf.count - 1) out << ", ";
        current = (current + 1) % buf.capacity;
    }
    out << "]";
    return out;
}

// ============================================================================
// MAIN FUNCTION
// ============================================================================
int main() {
    cout << "=== PART A: Pipeline Execution ===" << endl;

    // DataProcessor dp; // Compile Error Verification Line

    vector<DataProcessor*> pipeline;
    pipeline.push_back(new CSVProcessor());
    pipeline.push_back(new SensorStreamProcessor());

    for (auto* p : pipeline) {
        p->loadData("source_data");
        p->processData();
        p->printSummary();
        p->exportResult("output_dir");
        cout << "---" << endl;
    }

    // ------------------------------------------------------------------------
    // BONUS — dynamic_cast Safety Check Loop
    // ------------------------------------------------------------------------
    cout << "\n=== BONUS: dynamic_cast Traversal Check ===" << endl;
    for (auto* p : pipeline) {
        if (auto* csv = dynamic_cast<CSVProcessor*>(p)) {
            cout << "Found CSV Processor with " << csv->recordCount() << " records." << endl;
        }
        else if (auto* sensor = dynamic_cast<SensorStreamProcessor*>(p)) {
            cout << "Found Sensor Processor - Mean: " << sensor->getMean() << endl;
        }
    }

    /*
    ===========================================================================
    EXPLANATION: WHY static_cast IS UNSAFE HERE WHILE dynamic_cast IS SAFE
    ===========================================================================
    static_cast handles explicit downcasting strictly at compile-time without
    performing any runtime type checks. If we used static_cast to force a base
    pointer pointing to a SensorStreamProcessor into a CSVProcessor*, the compiler
    would blindly accept it. Any subsequent call to a method unique to CSVProcessor
    would reference incorrect, corrupt memory space, causing undefined behavior or
    an immediate crash.

    Conversely, dynamic_cast safely queries the object's Run-Time Type
    Information (RTTI) and yields a nullptr if the conversion is invalid, allowing
    safe conditional verification.
    */

    for (auto* p : pipeline) delete p;
    pipeline.clear();

    cout << "\n=== PART B: Circular DataBuffers ===" << endl;
    DataBuffer<int> tickBuffer(5);
    for (int i = 1; i <= 7; i++) tickBuffer.push(i * 10);
    cout << "Tick Buffer: " << tickBuffer << endl;

    DataBuffer<double> tempBuffer(4);
    tempBuffer.push(36.6); tempBuffer.push(37.1); tempBuffer.push(38.2); tempBuffer.push(36.9);
    cout << "Before pop: " << tempBuffer << endl;
    cout << "Popped: " << tempBuffer.pop() << endl;
    cout << "After pop: " << tempBuffer << endl;

    DataBuffer<string> logBuffer(3);
    logBuffer.push("INFO: Server started"); logBuffer.push("WARN: High memory usage");
    logBuffer.push("ERROR: DB connection timeout"); logBuffer.push("INFO: Retry successful");
    cout << "Log Buffer: " << logBuffer << endl;

    return 0;
}
