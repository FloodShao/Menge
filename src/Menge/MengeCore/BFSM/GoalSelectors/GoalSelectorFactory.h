/*
 Menge Crowd Simulation Framework

 Copyright and trademark 2012-17 University of North Carolina at Chapel Hill

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0
 or
    LICENSE.txt in the root of the Menge repository.

 Any questions or comments should be sent to the authors menge@cs.unc.edu

 <http://gamma.cs.unc.edu/Menge/>
*/

/*!
 @file    GoalSelectorFactory.h
 @brief    The factory for parsing xml data and instantiating goals.
 */

#ifndef __GOAL_SELECTOR_FACTORY_H__
#define __GOAL_SELECTOR_FACTORY_H__

#include "MengeCore/BFSM/GoalSelectors/GoalSelector.h"
#include "MengeCore/CoreConfig.h"
#include "MengeCore/PluginEngine/ElementFactory.h"

#include <string>

#include "thirdParty/tinyxml.h"

namespace Menge {

namespace BFSM {
/*!
 @brief    A class for parsing the xml description of a goal selector and instantiating particular
          instances.
 */
class MENGE_API GoalSelectorFactory : public ElementFactory<GoalSelector> {
 public:
  /*!
   @brief    Constructor.
   */
  GoalSelectorFactory();

 protected:
  /*!
   @brief    Given a pointer to a Goal Selector instance, sets the appropriate fields from the
            provided XML node.

   It is assumed that the value of the `type` attribute is this Goal Selector's type (i.e.
   GoalSelectorFactory::thisFactory has already been called and returned true). If sub-classes of
   GoalSelectorFactory introduce *new* GoalSelector parameters, then the sub-class should override
   this method but explicitly call the parent class's version.

   @param    selector      A pointer to the goal selector whose attributes are to be set.
   @param    node          The XML node containing the goal attributes.
   @param    behaveFldr    The path to the behavior file. If the condition references resources in
                          the file system, it should be defined relative to the behavior file
                          location. This is the folder containing that path.
   @returns  A boolean reporting success (true) or failure (false).
   */
  virtual bool setFromXML(GoalSelector* selector, TiXmlElement* node,
                          const std::string& behaveFldr) const;

  /*!
   @brief    The identifier for the "persistent" bool attribute.
   */
  size_t _persistentID;
};
}  // namespace BFSM
}  // namespace Menge
#endif  // __GOAL_SELECTOR_FACTORY_H__
