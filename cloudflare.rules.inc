<?php

/**
 * Implements hook_rules_file_info().
 */
function cloudflare_rules_file_info() {
  $items = array();
  $items[] = 'cloudflare.rules';

  return $items;
}

/**
 * Implements hook_rules_action_info() on behalf of the cloudflare module.
 */
function cloudflare_rules_action_info() {
  $items = array();

  $items['cloudflare_purge_node_cache'] = array(
    'label' => t("Purge CloudFlare cache for a node"),
    'group' => t("Node"),
    'base' => 'cloudflare_purge_node_rules_action',

    'parameter' => array(
      'node' => array(
        'type' => 'node',
        'label' => t("Content"),
      ),
    ),
  );
  return $items;
}

/**
 * Action: Purge CloudFlare cache for a given node.
 *
 * $param $node
 *   A node object
 *
 * @return
 *   An array containing the node object stored in the key called 'node' and an array containing the result
 *   of CloudFlare API call to purge operation.
 */
function cloudflare_purge_node_rules_action($node) {
  if (is_object($node)) {
    $r = _cloudflare_purge_node($node);
  }
  else {
    $r = NULL;
  }
  return array('node' => $node, $r);
}

?>
