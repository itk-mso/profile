<?php
/**
 * @file
 * loop_quick_box.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function loop_quick_box_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_quickbox'.
  $field_bases['field_quickbox'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_quickbox',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'text_long',
  );

  return $field_bases;
}
