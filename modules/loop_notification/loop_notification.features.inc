<?php
/**
 * @file
 * loop_notification.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function loop_notification_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function loop_notification_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_flag_default_flags().
 */
function loop_notification_flag_default_flags() {
  $flags = array();
  // Exported flag: "Message read".
  $flags['message_read'] = array(
    'entity_type' => 'message',
    'title' => 'Message read',
    'global' => 0,
    'types' => array(),
    'flag_short' => 'Mark as read',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'Mark as unread',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => 'Læst',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 0,
      'diff_standard' => 0,
      'message_notify_email_subject' => 0,
      'message_notify_email_body' => 0,
      'token' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'module' => 'loop_notification',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  return $flags;

}

/**
 * Implements hook_default_message_type().
 */
function loop_notification_default_message_type() {
  $items = array();
  $items['comment_added_to_post'] = entity_import('message_type', '{
    "name" : "comment_added_to_post",
    "description" : "Comment added to post",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "en",
    "arguments" : null,
    "message_text" : {
      "da" : [
        {
          "value" : "Der er kommet et nyt svar til sp\\u00f8rgsm\\u00e5let: \\u003Ca href=\\u0022\\/node\\/[message:field-message-node-reference:nid]\\u0022\\u003E[message:field-message-node-reference:field_description]\\u003C\\/a\\u003E",
          "format" : "html",
          "safe_value" : "Der er kommet et nyt svar til sp\\u00f8rgsm\\u00e5let: \\u003Ca href=\\u0022\\/node\\/[message:field-message-node-reference:nid]\\u0022\\u003E[message:field-message-node-reference:field_description]\\u003C\\/a\\u003E"
        }
      ],
      "en" : [
        {
          "value" : "There is a new reply to the question: \\u003Ca href=\\u0022\\/node\\/[message:field-message-node-reference:nid]\\u0022\\u003E[message:field-message-node-reference:field_description]\\u003C\\/a\\u003E",
          "format" : "html",
          "safe_value" : "There is a new reply to the question: \\u003Ca href=\\u0022\\/node\\/[message:field-message-node-reference:nid]\\u0022\\u003E[message:field-message-node-reference:field_description]\\u003C\\/a\\u003E"
        }
      ]
    }
  }');
  $items['comment_changed'] = entity_import('message_type', '{
    "name" : "comment_changed",
    "description" : "Comment changed",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "da",
    "arguments" : null,
    "message_text" : {
      "da" : [
        {
          "value" : "Et svar til sp\\u00f8rgsm\\u00e5let: \\u003Ca href=\\u0022\\/node\\/[message:field-message-node-reference:nid]\\u0022\\u003E[message:field-message-node-reference:field_description]\\u003C\\/a\\u003E er blevet \\u00e6ndret",
          "format" : "html",
          "safe_value" : "Et svar til sp\\u00f8rgsm\\u00e5let: \\u003Ca href=\\u0022\\/node\\/[message:field-message-node-reference:nid]\\u0022\\u003E[message:field-message-node-reference:field_description]\\u003C\\/a\\u003E er blevet \\u00e6ndret"
        }
      ],
      "en" : [
        {
          "value" : "There is a new reply to the question: \\u003Ca href=\\u0022\\/node\\/[message:field-message-node-reference:nid]\\u0022\\u003E[message:field-message-node-reference:field_description]\\u003C\\/a\\u003E",
          "format" : "html",
          "safe_value" : "There is a new reply to the question: \\u003Ca href=\\u0022\\/node\\/[message:field-message-node-reference:nid]\\u0022\\u003E[message:field-message-node-reference:field_description]\\u003C\\/a\\u003E"
        }
      ]
    }
  }');
  $items['document_added'] = entity_import('message_type', '{
    "name" : "document_added",
    "description" : "Document added",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "da",
    "arguments" : null,
    "message_text" : {
      "da" : [
        {
          "value" : "Et dokument er blevet oprettet: \\u003Ca href=\\u0022\\/node\\/[message:field-message-node-reference:nid]\\u0022\\u003E[message:field-message-node-reference:title]\\u003C\\/a\\u003E",
          "format" : "html",
          "safe_value" : "Et dokument er blevet oprettet: \\u003Ca href=\\u0022url]\\u0022\\u003E[message:field-message-node-reference:title]\\u003C\\/a\\u003E"
        }
      ],
      "en" : [
        {
          "value" : "A document has been added: \\u003Ca href=\\u0022\\/node\\/[message:field-message-node-reference:nid]\\u0022\\u003E[message:field-message-node-reference:title]\\u003C\\/a\\u003E",
          "format" : "html",
          "safe_value" : "A document has been added: \\u003Ca href=\\u0022url]\\u0022\\u003E[message:field-message-node-reference:title]\\u003C\\/a\\u003E"
        }
      ]
    }
  }');
  $items['document_collection_added'] = entity_import('message_type', '{
    "name" : "document_collection_added",
    "description" : "Document collection added",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "da",
    "arguments" : null,
    "message_text" : {
      "da" : [
        {
          "value" : "En dokumentsamling er blevet oprettet: \\u003Ca href=\\u0022\\/node\\/[message:field-message-node-reference:nid]\\u0022\\u003E[message:field-message-node-reference:title]\\u003C\\/a\\u003E",
          "format" : "html",
          "safe_value" : "En dokumentsamling er blevet oprettet: \\u003Ca href=\\u0022url]\\u0022\\u003E[message:field-message-node-reference:title]\\u003C\\/a\\u003E"
        }
      ],
      "en" : [
        {
          "value" : "A document collection has been added: \\u003Ca href=\\u0022\\/node\\/[message:field-message-node-reference:nid]\\u0022\\u003E[message:field-message-node-reference:title]\\u003C\\/a\\u003E",
          "format" : "html",
          "safe_value" : "A document collection has been added: \\u003Ca href=\\u0022url]\\u0022\\u003E[message:field-message-node-reference:title]\\u003C\\/a\\u003E"
        }
      ]
    }
  }');
  $items['document_collection_edited'] = entity_import('message_type', '{
    "name" : "document_collection_edited",
    "description" : "Document collection edited",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "da",
    "arguments" : null,
    "message_text" : {
      "da" : [
        {
          "value" : "En dokumentsamling er blevet \\u00e6ndret: \\u003Ca href=\\u0022\\/node\\/[message:field-message-node-reference:nid]\\u0022\\u003E[message:field-message-node-reference:title]\\u003C\\/a\\u003E",
          "format" : "html",
          "safe_value" : "En dokumentsamling er blevet \\u00e6ndret: \\u003Ca href=\\u0022url]\\u0022\\u003E[message:field-message-node-reference:title]\\u003C\\/a\\u003E"
        }
      ],
      "en" : [
        {
          "value" : "A document collection has been edited: \\u003Ca href=\\u0022\\/node\\/[message:field-message-node-reference:nid]\\u0022\\u003E[message:field-message-node-reference:title]\\u003C\\/a\\u003E",
          "format" : "html",
          "safe_value" : "A document collection has been edited: \\u003Ca href=\\u0022url]\\u0022\\u003E[message:field-message-node-reference:title]\\u003C\\/a\\u003E"
        }
      ]
    }
  }');
  $items['document_edited'] = entity_import('message_type', '{
    "name" : "document_edited",
    "description" : "Document edited",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "da",
    "arguments" : null,
    "message_text" : {
      "da" : [
        {
          "value" : "Et dokument er blevet \\u00e6ndret: \\u003Ca href=\\u0022\\/node\\/[message:field-message-node-reference:nid]\\u0022\\u003E[message:field-message-node-reference:title]\\u003C\\/a\\u003E",
          "format" : "html",
          "safe_value" : "Et dokument er blevet \\u00e6ndret: \\u003Ca href=\\u0022url]\\u0022\\u003E[message:field-message-node-reference:title]\\u003C\\/a\\u003E"
        }
      ],
      "en" : [
        {
          "value" : "A document has been edited: \\u003Ca href=\\u0022\\/node\\/[message:field-message-node-reference:nid]\\u0022\\u003E[message:field-message-node-reference:title]\\u003C\\/a\\u003E",
          "format" : "html",
          "safe_value" : "A document has been edited: \\u003Ca href=\\u0022url]\\u0022\\u003E[message:field-message-node-reference:title]\\u003C\\/a\\u003E"
        }
      ]
    }
  }');
  $items['node_added'] = entity_import('message_type', '{
    "name" : "node_added",
    "description" : "Node added",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "da",
    "arguments" : null,
    "message_text" : {
      "da" : [
        {
          "value" : "Der er kommet et nyt sp\\u00f8rgsm\\u00e5l til et emne du f\\u00f8lger \\u003Ca href=\\u0022\\/node\\/[message:field-message-node-reference:nid]\\u0022\\u003E[message:field-message-node-reference:field_description]\\u003C\\/a\\u003E",
          "format" : "html",
          "safe_value" : "Der er kommet et nyt sp\\u00f8rgsm\\u00e5l til et emne du f\\u00f8lger \\u003Ca href=\\u0022\\/node\\/[message:field-message-node-reference:nid]\\u0022\\u003E[message:field-message-node-reference:field_description]\\u003C\\/a\\u003E"
        }
      ],
      "en" : [
        {
          "value" : "There is a new reply to the question: \\u003Ca href=\\u0022\\/node\\/[message:field-message-node-reference:nid]\\u0022\\u003E[message:field-message-node-reference:field_description]\\u003C\\/a\\u003E",
          "format" : "html",
          "safe_value" : "There is a new reply to the question: \\u003Ca href=\\u0022\\/node\\/[message:field-message-node-reference:nid]\\u0022\\u003E[message:field-message-node-reference:field_description]\\u003C\\/a\\u003E"
        }
      ]
    }
  }');
  $items['node_edited'] = entity_import('message_type', '{
    "name" : "node_edited",
    "description" : "Node edited",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "da",
    "arguments" : null,
    "message_text" : {
      "da" : [
        {
          "value" : "Et sp\\u00f8rgsm\\u00e5l du f\\u00f8lger er blevet \\u00e6ndret \\u003Ca href=\\u0022\\/node\\/[message:field-message-node-reference:nid]\\u0022\\u003E[message:field-message-node-reference:field_description]\\u003C\\/a\\u003E",
          "format" : "html",
          "safe_value" : "Et sp\\u00f8rgsm\\u00e5l du f\\u00f8lger er blevet \\u00e6ndret \\u003Ca href=\\u0022\\/node\\/[message:field-message-node-reference:nid]\\u0022\\u003E[message:field-message-node-reference:field_description]\\u003C\\/a\\u003E"
        }
      ],
      "en" : [
        {
          "value" : "There is a new reply to the question: \\u003Ca href=\\u0022\\/node\\/[message:field-message-node-reference:nid]\\u0022\\u003E[message:field-message-node-reference:field_description]\\u003C\\/a\\u003E",
          "format" : "html",
          "safe_value" : "There is a new reply to the question: \\u003Ca href=\\u0022\\/node\\/[message:field-message-node-reference:nid]\\u0022\\u003E[message:field-message-node-reference:field_description]\\u003C\\/a\\u003E"
        }
      ]
    }
  }');
  return $items;
}
