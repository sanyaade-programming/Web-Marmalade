/*
 * Copyright (C) 2001-2012 Ideaworks3D Ltd.
 * All Rights Reserved.
 *
 * This document is protected by copyright, and contains information
 * proprietary to Ideaworks Labs.
 * This file consists of source code released by Ideaworks Labs under
 * the terms of the accompanying End User License Agreement (EULA).
 * Please do not use this program/source code before you have read the
 * EULA and have agreed to be bound by its terms.
 */
/*
 * WARNING: this is an autogenerated file and will be overwritten by
 * the extension interface script.
 */
#ifndef S3E_EXT_OVERLAY_H
#define S3E_EXT_OVERLAY_H

#include <s3eTypes.h>

/**
 * @defgroup overlayapigroup MW Overlay API Reference
 *
 * This extension provides Overlay functionality for Web Marmalade Apps. The overlay fully covers
 * part of the screen (defined in the create function) thus no touches are registered for any
 * item(s) underneath this defined section.
 */

/**
 * @}
 * @addtogroup overlayapigroup
 * @{
 */
 
/** Opaque handle to an overlay object */
typedef struct s3eOverlay s3eOverlay;

// -- s3eOverlay_Enums --
//=================================================================================================
//#################################################################################################
/**
 * s3eOverlay Callbacks
 *
 * Callbacks can only have the following function signature:
 * int32 FunctionName(void* systemData, void* userData)
 * Parameters:
 * systemData: This value is different for every callback type and described below.
 * userData: Arbitrary data that can be passed to the callback; This value is specified via the
 * function s3eOverlayRegister.
 *
 * Note: Data passed into the callback function via the systemData parameter is only valid for the
 * duration of the callback.
 *
 */
typedef enum s3eOverlayCallback
{
    /**
     * Called if any button in the overlay is clicked. The number of the button clicked is returned
     * to the callback through the system data as an int.
     */
    S3E_OVERLAY_BUTTON_CLICKED = 1,

    S3E_OVERLAY_CALLBACK_MAX = 2
} s3eOverlayCallback;

/**
 * Defines the type of item that is held within the overlay
 *
 * @par Required Header Files
 * s3eGree.h
 */
typedef enum s3eOverlayEItem
{
    /** An s3eOverlay button item */
    S3E_OVERLAY_ITEM_BUTTON = 1,

    /** An s3eOverlay image item */
    S3E_OVERLAY_ITEM_IMAGE = 2,

    /** An s3eOverlay image item */
    S3E_OVERLAY_ITEM_LABEL = 3

} s3eOverlayEItem;

/**
 * Defines the background colour of the overlay
 *
 * @par Required Header Files
 * s3eGree.h
 */
typedef enum s3eOverlayEColour
{
    S3E_OVERLAY_COLOUR_CLEAR      = 0,  // Clear (No Background)
    S3E_OVERLAY_COLOUR_BLACK      = 1,  // Black
    S3E_OVERLAY_COLOUR_DARKGREY   = 2,  // Dark Grey
    S3E_OVERLAY_COLOUR_LIGHTGREY  = 3,  // Light Grey
    S3E_OVERLAY_COLOUR_WHITE      = 4,  // White
    S3E_OVERLAY_COLOUR_RED        = 5,  // Red
    S3E_OVERLAY_COLOUR_GREEN      = 6,  // Green
    S3E_OVERLAY_COLOUR_BLUE       = 7,  // Blue
    S3E_OVERLAY_COLOUR_YELLOW     = 8,  // Yellow
    S3E_OVERLAY_COLOUR_ORANGE     = 9,  // Orange
    S3E_OVERLAY_COLOUR_PURLPE     = 10, // Purple
    S3E_OVERLAY_COLOUR_BROWN      = 11  // Brown
} s3eOverlayEColour;
// \cond HIDDEN_DEFINES
S3E_BEGIN_C_DECL
// \endcond

/**
 * Returns S3E_TRUE if the Overlay extension is available.
 */
s3eBool s3eOverlayAvailable();

/**
 * Registers a callback to be called for an operating system event.
 *
 * The available callback types are listed in @ref s3eOverlayCallback.
 * @param cbid ID of the event for which to register.
 * @param fn callback function.
 * @param userdata Value to pass to the @e userdata parameter of @e NotifyFunc.
 * @return
 *  - @ref S3E_RESULT_SUCCESS if no error occurred.
 *  - @ref S3E_RESULT_ERROR if the operation failed.\n
 *
 * @see s3eOverlayUnRegister
 * @note For more information on the system data passed as a parameter to the callback
 * registered using this function, see the @ref s3eOverlayCallback enum.
 */
s3eResult s3eOverlayRegister(s3eOverlayCallback cbid, s3eCallback fn, void* userData);

/**
 * Unregister a callback for a given event.
 * @param cbid ID of the callback for which to register.
 * @param fn Callback Function.
 * @return
 * - @ref S3E_RESULT_SUCCESS if no error occurred.
 * - @ref S3E_RESULT_ERROR if the operation failed.\n
 * @note For more information on the systemData passed as a parameter to the callback
 * registered using this function, see the s3eOverlayCallback enum.
 * @note It is not necessary to define a return value for any registered callback.
 * @see s3eOverlayRegister
 */
s3eResult s3eOverlayUnRegister(s3eOverlayCallback cbid, s3eCallback fn);

/**
 * Create a s3eOverlay item. The s3eOverlay should appear above all other objects that are created
 * before it. The default background colour for this is clear (no colour). If 0 is used for width
 * or height, these will be set to the screen with or height.
 *
 * @param xPos      x position of the overlay (from Left of device surface)
 * @param yPos      y position of the overlay (from Top of device surface)
 * @param width     total width of the overlay (left to right)
 * @param height    total height of the overlay (top to bottom)
 *
 * @return          handle to the created control
 *
 * @par Required Header Files
 * s3eOverlay.h
 */
s3eOverlay* s3eOverlayCreate(const unsigned int xPos S3E_DEFAULT(0), const unsigned int yPos S3E_DEFAULT(0), const unsigned int width S3E_DEFAULT(0), const unsigned int height S3E_DEFAULT(0));

/**
 * Destroy created s3eOverlay item (if it exists) and remove it from the screen.
 *
 * @param handle    handle of the control to delete
 *
 * @par Required Header Files
 * s3eOverlay.h
 */
s3eResult s3eOverlayDestroy(s3eOverlay* handle);

/**
 * Reposition the s3eOverlay item (if it exists).
 * Must call s3eOverlayCreate first.
 *
 * @param handle    handle of the control
 * @param xPos      x position of the overlay (from Left of device surface)
 * @param yPos      y position of the overlay (from Top of device surface)
 *
 * @par Required Header Files
 * s3eOverlay.h
 */
void s3eOverlaySetPosition(s3eOverlay* handle, const unsigned int x S3E_DEFAULT(0), const unsigned int y S3E_DEFAULT(0));

/**
 * Resize the s3eOverlay item (if it exists). If 0 is used for width or height, these will be set
 * to the screen with or height.
 * Must call s3eOverlayCreate first.
 *
 * @param handle    handle of the control
 * @param width     total width of the overlay (left to right)
 * @param height    total height of the overlay (top to bottom)
 *
 * @par Required Header Files
 * s3eOverlay.h
 */
void s3eOverlayResize(s3eOverlay* handle, const unsigned int width S3E_DEFAULT(0), const unsigned int height S3E_DEFAULT(0));

/**
 * Set the background using preset (enum) colour components.
 *
 * @param handle    handle of the control
 * @param colour    Colour for the s3eOverlay background (see: s3eOverlayEColour enum)
 *
 * @par Required Header Files
 * s3eOverlay.h
 */
void s3eOverlaySetBackgroundColour(s3eOverlay* handle, const s3eOverlayEColour colour S3E_DEFAULT(S3E_OVERLAY_COLOUR_CLEAR));

/**
 * Add an item to the s3eOverlay specified. Only one item can be added to a s3eOverlay at any one time. If 0 is used
 * for width or height, these will be set to the s3eOverlay with or height. If an item is positioned and/or
 * sized as to not fit correctly on either x or y axes the item will automatically use 100% of the s3eOverlay
 * width/height on this axis
 *
 * @param handle    handle of the parent
 * @param itemType  The type of item to be added to the overlay (see: s3eOverlayEItem enum)
 * @param xPos      The button x Position (Percentage of parent s3eOverlay width (left to right))
 * @param yPos      The button y Position (Percentage of parent s3eOverlay height (top to bottom))
 * @param width     The button width (Percentage of parent s3eOverlay width)
 * @param height    The button hieght (Percentage of parent s3eOverlay height)
 *
 * Note: If 0 is passed for width or height it will be set to 100% of the s3eOverlay width/height.
 *
 * @return Returns S3E_RESULT_SUCCESS if the item was created successfully. S3E_RESULT_ERROR is
 *         returned if an item already exists.
 *
 * @par Required Header Files
 * s3eOverlay.h
 */
s3eResult s3eOverlayAddItem(s3eOverlay* handle, const s3eOverlayEItem item, const unsigned int xPos S3E_DEFAULT(0), const unsigned int yPos S3E_DEFAULT(0),  const unsigned int width S3E_DEFAULT(0), const unsigned int height S3E_DEFAULT(0));

/**
 * Remove item from the s3eOverlay specified. If there is no item present S3E_RESULT_ERROR will be returned.
 *
 * @param handle    handle of the item to remove
 * @return Returns S3E_RESULT_SUCCESS if the item was removed successfully
 *
 * @par Required Header Files
 * s3eOverlay.h
 */
s3eResult s3eOverlayRemoveItem(s3eOverlay* handle);

S3E_END_C_DECL

#endif /* !S3E_EXT_OVERLAY_H */