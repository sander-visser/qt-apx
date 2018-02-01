#ifndef QAPXSIMPLEPORT_H
#define QAPXSIMPLEPORT_H

class QApxSimplePort
{
public:
   QApxSimplePort(const char *name, const char *dsg, const char *attr);
   virtual ~QApxSimplePort();
   const char *getName() const {return mName;}
   const char *getDataSignature() const {return mDsg;}
   const char *getAttr() const {return mAttr;}
   virtual bool isRequire() const = 0;
   int getPortIndex() const {return mPortIndex;}
   void setPortIndex(int value){mPortIndex=value;}
protected:
   char *mName; //strong reference to name
   char *mDsg; //strong reference to data signature
   char *mAttr; //strong reference to port attribute string
   int mPortIndex;
};

class QApxSimpleRequirePort : public QApxSimplePort
{
public:
   QApxSimpleRequirePort(const char *name, const char *dsg, const char *attr);
   bool isRequire() const {return true;}
};

class QApxSimpleProvidePort : public QApxSimplePort
{
public:
   QApxSimpleProvidePort(const char *name, const char *dsg, const char *attr);
   bool isRequire() const {return false;}
};


#endif // QAPXSIMPLEPORT_H
