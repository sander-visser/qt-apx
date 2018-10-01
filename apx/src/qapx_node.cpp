#include "qapx_node.h"
#include <QDebug>

namespace Apx
{
   Node::Node()
   {

   }

   Node::~Node()
   {
      DataTypeListIterator it;
      PortListIterator it2;
      for(it2=mRequirePorts.begin();it2!=mRequirePorts.end();it2++)
      {
         QApxSimplePort *port = *it2;
         if(port != nullptr)
         {
            delete port;
         }
      }
      for(it2=mProvidePorts.begin();it2!=mProvidePorts.end();it2++)
      {
         QApxSimplePort *port = *it2;
         if(port != nullptr)
         {
            delete port;
         }
      }
      for (it=mDataTypes.begin(); it!= mDataTypes.end(); it++)
      {
         QApxDataType* dataType = *it;
         if (dataType != nullptr)
         {
            delete dataType;
         }
      }
   }

   void Node::appendType(QApxDataType *dataType)
   {
      mDataTypes.append(dataType);
   }

   QApxDataType *Node::getTypeById(int i) const
   {
      if (i<mDataTypes.size())
      {
         return mDataTypes.at(i);
      }
      return nullptr;
   }

   void Node::appendRequirePort(QApxSimpleRequirePort *port)
   {
      QApxSimplePort* simplePort = static_cast<QApxSimplePort*>(port);
      if (simplePort!=nullptr)
      {
         mRequirePorts.append(simplePort);
         mPortMap.insert(QString(simplePort->getName()),simplePort);
      }
      else
      {
         qDebug() << "appendRequirePort called with null";
      }
   }

   void Node::appendProvidePort(QApxSimpleProvidePort *port)
   {
      QApxSimplePort* simplePort = static_cast<QApxSimplePort*>(port);
      if (simplePort!=nullptr)
      {
         mProvidePorts.append(simplePort);
         mPortMap.insert(QString(simplePort->getName()),simplePort);
      }
      else
      {
         qDebug() << "appendProvidePort called with null";
      }
   }

   QApxSimplePort *Node::getRequirePortById(int i) const
   {
      if (i< mRequirePorts.size())
      {
         return mRequirePorts.at(i);
      }
      return nullptr;
   }

   QApxSimplePort *Node::getProvidePortById(int i) const
   {
      if (i< mProvidePorts.size())
      {
         return mProvidePorts.at(i);
      }
      return nullptr;
   }

   QApxSimplePort *Node::findPortByName(const char *name) const
   {
      PortMapItertator it = mPortMap.find(QString(name));
      if (it != mPortMap.end())
      {
         return it.value();
      }
      return nullptr;
   }

   void Node::setName(const QString &name)
   {
      mName=name;
   }

   const QString &Node::getName() const
   {
      return mName;
   }
}
