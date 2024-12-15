#ifndef FOOMANAGER_H
#define FOOMANAGER_H

class FooManager {
public:
    int GetSampleData() {
        return SampleData;
    }

    static void Create() {
        if (m_Inst == nullptr) {
            m_Inst = new FooManager();
        }
    }

    static FooManager* GetInst() {
        return m_Inst;
    }

protected:
    FooManager();
    virtual ~FooManager();

private:
    int SampleData;
    static FooManager* m_Inst;
};

#endif
